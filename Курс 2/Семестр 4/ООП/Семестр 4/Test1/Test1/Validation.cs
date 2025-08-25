using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Input;

namespace Test1
{
    public class ValidText
    {
        [NoEnglishLetters(ErrorMessage = "Никаких английских букв")]
        public string Text { get; set; }
        public ValidText() { }
    }

    public class NoEnglishLettersAttribute : ValidationAttribute
    {
        public override bool IsValid(object value)
        {
            var str = value as string;
            if (string.IsNullOrEmpty(str))
                return true;

            return !Regex.IsMatch(str, "[A-Za-z]");
        }
    }
}
