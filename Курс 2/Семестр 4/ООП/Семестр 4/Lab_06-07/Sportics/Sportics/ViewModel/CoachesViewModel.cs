using Sportics.Helper;
using Sportics.Model;
using Sportics.View;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Windows;
using System.Windows.Input;

namespace Sportics.ViewModel
{
    public class CoachesViewModel : BaseViewModel
    {
        public List<Coach> Coaches { get; set; }
        public ObservableCollection<Coach> FilteredCoaches { get; set; }

        public List<string> Categories { get; set; } = new List<string>
        {
            "Все категории", "Фитнес", "Йога", "Танцы", "Плавание", "Тренажерный зал"
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

        private string selectedCategory = "Все категории";
        public string SelectedCategory
        {
            get => selectedCategory;
            set
            {
                selectedCategory = value;
                OnPropertyChanged();
            }
        }

        private string _newCoachName;
        public string NewCoachName
        {
            get => _newCoachName;
            set
            {
                _newCoachName = value;
                OnPropertyChanged();
            }
        }


        public ICommand OpenAdminCommand { get; }
        public ICommand OpenAddCoachCommand { get; }
        public ICommand DetailsCommand { get; }
        public ICommand ApplyFilterCommand { get; }
        public ICommand SearchCommand { get; }
        public ICommand OpenAccountCommand { get; }
        public ICommand SayHelloCommand { get; }

        public CoachesViewModel()
        {
            OpenAddCoachCommand = new RelayCommand(obj => OpenAddCoach());
            OpenAdminCommand = new RelayCommand(obj => OpenAdmin());
            DetailsCommand = new RelayCommand(obj => GetDetails((Coach)obj));
            ApplyFilterCommand = new RelayCommand(obj => ApplyFilter());
            SearchCommand = new RelayCommand(obj => Search());
            OpenAccountCommand = new RelayCommand(obj => OpenAccount());

            SayHelloCommand = new RelayCommand(obj => MessageBox.Show("Ну привет"));
            CommandManager.RegisterClassCommandBinding(typeof(Window),
                new CommandBinding(CustomCommands.SayHelloCommand, (s, e) => SayHelloCommand.Execute(null)));

            LoadCoaches();
        }

        private void LoadCoaches()
        {
            Coaches = DataWorker.GetAllCoaches();
            FilteredCoaches = new ObservableCollection<Coach>(Coaches);
            OnPropertyChanged(nameof(Coaches));
            OnPropertyChanged(nameof(FilteredCoaches));
        }

        private void ApplyFilter()
        {
            List<Coach> filtered = Coaches
                .Where(c => SelectedCategory == "Все категории" || c.Specialization == SelectedCategory)
                .ToList();

            FilteredCoaches = new ObservableCollection<Coach>(filtered);
            OnPropertyChanged(nameof(FilteredCoaches));
        }

        private void Search()
        {
            List<Coach> filtered = Coaches
                .Where(c => string.IsNullOrWhiteSpace(NewCoachName) || c.Name.Contains(NewCoachName))
                .ToList();

            FilteredCoaches = new ObservableCollection<Coach>(filtered);
            OnPropertyChanged(nameof(FilteredCoaches));
        }

        private void OpenAddCoach()
        {
            AddCoachWindow window = new AddCoachWindow
            {
                Owner = Application.Current.MainWindow,
                WindowStartupLocation = WindowStartupLocation.CenterOwner
            };

            AddCoachViewModel viewModel = new AddCoachViewModel();

            window.DataContext = viewModel;
            viewModel.RequestClose += () => window.Close();

            window.ShowDialog();
            LoadCoaches();
        }

        private void OpenAdmin()
        {
            AdminWindow adminWindow = new AdminWindow();
            Application.Current.MainWindow = adminWindow;

            Application.Current.Windows
                .OfType<Window>()
                .FirstOrDefault(w => w is CoachesWindow)?
                .Close();

            Application.Current.MainWindow.Show();
        }

        private void GetDetails(Coach coach)
        {
            CoachInfoWindow window = new CoachInfoWindow();
            CoachInfoViewModel vm = new CoachInfoViewModel(coach);
            window.DataContext = vm;
            vm.RequestClose += () => window.Close();
            window.Owner = Application.Current.MainWindow;
            window.WindowStartupLocation = WindowStartupLocation.CenterOwner;
            window.ShowDialog();

            LoadCoaches();
        }

        private void OpenAccount()
        {
            AccountWindow accountWindow = new AccountWindow
            {
                Owner = Application.Current.MainWindow,
                WindowStartupLocation = WindowStartupLocation.CenterOwner
            };
            accountWindow.ShowDialog();
        }
    }
}
