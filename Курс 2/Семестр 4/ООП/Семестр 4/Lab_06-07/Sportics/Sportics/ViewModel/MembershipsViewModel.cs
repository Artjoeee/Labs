using Sportics.Helper;
using Sportics.Model;
using Sportics.View;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Input;

namespace Sportics.ViewModel
{
    public interface IUndoableCommand
    {
        void Execute();
        void Undo();
    }

    public class UndoRedoManager : INotifyPropertyChanged
    {
        private static readonly Lazy<UndoRedoManager> _instance = new Lazy<UndoRedoManager>(() => new UndoRedoManager());
        public static UndoRedoManager Instance => _instance.Value;

        private readonly Stack<IUndoableCommand> undoStack = new Stack<IUndoableCommand>();
        private readonly Stack<IUndoableCommand> redoStack = new Stack<IUndoableCommand>();

        public event PropertyChangedEventHandler PropertyChanged;

        private void OnPropertyChanged(string propertyName)
            => PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));

        public void Execute(IUndoableCommand command)
        {
            command.Execute();
            undoStack.Push(command);
            redoStack.Clear();
            OnPropertyChanged(nameof(CanUndo));
            OnPropertyChanged(nameof(CanRedo));
        }

        public void Undo()
        {
            if (CanUndo)
            {
                var command = undoStack.Pop();
                command.Undo();
                redoStack.Push(command);
                OnPropertyChanged(nameof(CanUndo));
                OnPropertyChanged(nameof(CanRedo));
            }
        }

        public void Redo()
        {
            if (CanRedo)
            {
                try
                {
                    var command = redoStack.Pop();
                    command.Execute();
                    undoStack.Push(command);
                }
                catch (Exception ex)
                {
                    // Логирование или окно сообщения
                    System.Windows.MessageBox.Show("Ошибка при Redo: " + ex.Message);
                }

                OnPropertyChanged(nameof(CanUndo));
                OnPropertyChanged(nameof(CanRedo));
            }
        }

        public bool CanUndo => undoStack.Any();
        public bool CanRedo => redoStack.Any();
    }



    public class UndoableAction : IUndoableCommand
    {
        private readonly Action executeAction;
        private readonly Action undoAction;
        private bool hasExecuted = false;

        public UndoableAction(Action execute, Action undo)
        {
            executeAction = execute;
            undoAction = undo;
        }

        public void Execute()
        {
            if (!hasExecuted)
            {
                executeAction();
                hasExecuted = true;
            }
            else
            {
                // Повторное выполнение (redo)
                executeAction();
            }
        }

        public void Undo()
        {
            undoAction();
        }
    }



    public class MembershipsViewModel : BaseViewModel, IDataErrorInfo
    {
        public ICommand UndoCommand { get; }
        public ICommand RedoCommand { get; }
        public ICommand DeleteCommand { get; }


        public List<Membership> Memberships { get; set; }
        public ObservableCollection<Membership> FilteredMemberships { get; set; }

        public List<string> Categories { get; set; } = new List<string>
        {
            "Все категории", "Фитнес", "Йога", "Бассейн", "Тренажерный зал", "Танцы"
        };

        public ObservableCollection<string> Languages { get; } = new ObservableCollection<string> { "RU", "EN" };


        private string _selectedLanguage = "RU";
        public string SelectedLanguage
        {
            get => _selectedLanguage;
            set
            {
                if (_selectedLanguage != value)
                {
                    _selectedLanguage = value;
                    OnPropertyChanged();
                    LocalizationManager.ChangeCulture(value);
                }
            }
        }

        private readonly ThemeService ThemeService = ThemeService.Instance;

        public bool IsDarkTheme
        {
            get => ThemeService.IsDarkTheme;
            set
            {
                if (value)
                    ThemeService.SetDarkTheme();
                else
                    ThemeService.SetLightTheme();

                OnPropertyChanged();
            }
        }


        private string priceFrom;
        public string PriceFrom
        {
            get => priceFrom;
            set
            {
                priceFrom = value;
                OnPropertyChanged(nameof(PriceFrom));
                IsValidationActive = false;
            }
        }

        private string priceTo;
        public string PriceTo
        {
            get => priceTo;
            set
            {
                priceTo = value;
                OnPropertyChanged(nameof(PriceTo));
                IsValidationActive = false;
            }
        }

        private string selectedCategory = "Все категории";
        public string SelectedCategory
        {
            get => selectedCategory;
            set
            {
                selectedCategory = value;
                OnPropertyChanged(nameof(SelectedCategory));
            }
        }

        private bool isValidationActive = false;
        public bool IsValidationActive
        {
            get => isValidationActive;
            set
            {
                isValidationActive = value;
                OnPropertyChanged(nameof(IsValidationActive));
            }
        }

        public string Error => null;

        public string this[string columnName]
        {
            get
            {
                if (!IsValidationActive) return null;

                switch (columnName)
                {
                    case nameof(PriceFrom):
                        if (!string.IsNullOrWhiteSpace(PriceFrom) && !Regex.IsMatch(PriceFrom, @"^\d+$"))
                            return "Введите положительное число";
                        break;
                    case nameof(PriceTo):
                        if (!string.IsNullOrWhiteSpace(PriceTo) && !Regex.IsMatch(PriceTo, @"^\d+$"))
                            return "Введите положительное число";
                        break;
                }

                return null;
            }
        }

        public ICommand OpenAccountCommand { get; }
        public ICommand OpenAddMembershipCommand { get; }
        public ICommand OpenAdminCommand { get; }
        public ICommand DetailsCommand { get; }
        public ICommand ApplyFilterCommand { get; }

        public MembershipsViewModel()
        {
            OpenAccountCommand = new RelayCommand(obj => OpenAccount());
            OpenAddMembershipCommand = new RelayCommand(obj => OpenAddMembership());
            OpenAdminCommand = new RelayCommand(obj => OpenAdmin());
            DetailsCommand = new RelayCommand(obj => GetDetails((Membership)obj));
            ApplyFilterCommand = new RelayCommand(obj => ApplyFilter());

            UndoCommand = new RelayCommand(obj => UndoRedoManager.Instance.Undo(), obj => UndoRedoManager.Instance.CanUndo);
            RedoCommand = new RelayCommand(obj => UndoRedoManager.Instance.Redo(), obj => UndoRedoManager.Instance.CanRedo);

            DeleteCommand = new RelayCommand(obj => DeleteMembership(obj as Membership));

            UndoRedoManager.Instance.PropertyChanged += (s, e) =>
            {
                if (e.PropertyName == nameof(UndoRedoManager.CanUndo) || e.PropertyName == nameof(UndoRedoManager.CanRedo))
                {
                    Application.Current.Dispatcher.Invoke(() =>
                    {
                        CommandManager.InvalidateRequerySuggested();
                    });
                }
            };

            AllMemberships();
        }

        private void DeleteMembership(Membership membership)
        {
            if (membership == null) return;

            var backup = new Membership
            {
                FullName = membership.FullName,
                ShortName = membership.ShortName,
                Category = membership.Category,
                Description = membership.Description,
                Price = membership.Price,
                Photo = membership.Photo,
                DurationInDays = membership.DurationInDays
            };

            UndoRedoManager.Instance.Execute(new UndoableAction(
                execute: () =>
                {
                    // Удалить по Id
                    var existing = Memberships.FirstOrDefault(m => m.Id == membership.Id);
                    if (existing != null)
                    {
                        DataWorker.DeleteMembership(existing);
                        Memberships.Remove(existing);
                        FilteredMemberships.Remove(existing);
                        OnPropertyChanged(nameof(FilteredMemberships));
                    }
                },
                undo: () =>
                {
                    // Повторно добавить и сохранить Id
                    var restored = DataWorker.AddMembership(
                        backup.FullName,
                        backup.ShortName,
                        backup.Category,
                        backup.Description,
                        backup.Price,
                        backup.Photo,
                        backup.DurationInDays
                    );

                    // Обновим Id в backup, чтобы Redo снова сработал
                    membership.Id = restored.Id;

                    Memberships.Add(restored);
                    FilteredMemberships.Add(restored);
                    OnPropertyChanged(nameof(FilteredMemberships));
                }
            ));
        }





        private void AllMemberships()
        {
            Memberships = DataWorker.GetAllMemberships();
            FilteredMemberships = new ObservableCollection<Membership>(Memberships);
            OnPropertyChanged(nameof(Memberships));
            OnPropertyChanged(nameof(FilteredMemberships));
        }

        private void ApplyFilter()
        {
            IsValidationActive = true;
            OnPropertyChanged(nameof(PriceFrom));
            OnPropertyChanged(nameof(PriceTo));

            if (!string.IsNullOrEmpty(this[nameof(PriceFrom)]) || !string.IsNullOrEmpty(this[nameof(PriceTo)]))
                return;

            decimal.TryParse(PriceFrom, out decimal from);
            decimal.TryParse(PriceTo, out decimal to);

            List<Membership> filtered = Memberships.Where(m =>
                (string.IsNullOrEmpty(SelectedCategory) || SelectedCategory == "Все категории" || m.Category == SelectedCategory) &&
                (string.IsNullOrWhiteSpace(PriceFrom) || m.Price >= from) &&
                (string.IsNullOrWhiteSpace(PriceTo) || m.Price <= to)).ToList();

            FilteredMemberships = new ObservableCollection<Membership>(filtered);
            OnPropertyChanged(nameof(FilteredMemberships));
        }

        private void OpenAddMembership()
        {
            AddWindow window = new AddWindow
            {
                Owner = Application.Current.MainWindow,
                WindowStartupLocation = WindowStartupLocation.CenterOwner
            };

            AddViewModel vm = new AddViewModel();
            window.DataContext = vm;

            vm.RequestClose += () =>
            {
                window.Close();

                if (vm.CreatedMembership != null)
                {
                    var addedMembership = vm.CreatedMembership;

                    var addCommand = new UndoableAction(
                        execute: () =>
                        {
                            if (!Memberships.Any(m => m.Id == addedMembership.Id))
                            {
                                Memberships.Add(addedMembership);
                                FilteredMemberships.Add(addedMembership);
                                OnPropertyChanged(nameof(FilteredMemberships));
                            }
                        },
                        undo: () =>
                        {
                            var toRemove = Memberships.FirstOrDefault(m => m.Id == addedMembership.Id);
                            if (toRemove != null)
                            {
                                DataWorker.DeleteMembership(toRemove);
                                Memberships.Remove(toRemove);
                                FilteredMemberships.Remove(toRemove);
                                OnPropertyChanged(nameof(FilteredMemberships));
                            }
                        }
                    );

                    UndoRedoManager.Instance.Execute(addCommand);
                }
            };

            window.ShowDialog();
        }





        private void OpenAdmin()
        {
            AdminWindow adminWindow = new AdminWindow();
            Application.Current.MainWindow = adminWindow;

            Application.Current.Windows
                .OfType<Window>()
                .FirstOrDefault(w => w is MembershipsWindow)?
                .Close();

            Application.Current.MainWindow.Show();
        }

        private void OpenAccount()
        {
            AccountWindow accountWindow = new AccountWindow();
            accountWindow.Owner = Application.Current.MainWindow;
            accountWindow.WindowStartupLocation = WindowStartupLocation.CenterOwner;
            accountWindow.ShowDialog();
        }

        private void GetDetails(Membership membership)
        {
            MembershipInfoWindow window = new MembershipInfoWindow();
            MembershipInfoViewModel viewModel = new MembershipInfoViewModel(membership);
            window.DataContext = viewModel;
            viewModel.RequestClose += () => window.Close();
            window.Owner = Application.Current.MainWindow;
            window.WindowStartupLocation = WindowStartupLocation.CenterOwner;
            window.ShowDialog();

            AllMemberships();
        }
    }
}
