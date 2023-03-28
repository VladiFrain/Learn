using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace AsyncCustomCommand
{
    internal class MainWindowViewModel : INotifyPropertyChanged
    {
        public MainWindowViewModel()
        {
            this.CurrentName = "Name";
            this.CurrentSurname = "Surname";
            this.IsButtonEnabled = true;
        }

        private ObservableCollection<Person> _persons = new ObservableCollection<Person>();
        public ObservableCollection<Person> Persons
        {
            get => _persons;
            set
            {
                _persons = value;
            }
        }

        private string? _currentSurname;
        public string? CurrentSurname
        {
            get => _currentSurname;
            set
            {
                _currentSurname = value;
                RaisePropertyChanged();
            }
        }

        private string? _currentName;
        public string? CurrentName
        {
            get => _currentName;
            set
            {
                _currentName = value;
                RaisePropertyChanged();
            }
        }

        private bool _isButtonEnabled;
        public bool IsButtonEnabled
        {
            get => _isButtonEnabled;
            set
            {
                _isButtonEnabled = value;
                RaisePropertyChanged();
            }
        }

        private Person _selectedPerson;
        public Person SelectedPerson
        {
            get => _selectedPerson;
            set
            {
                _selectedPerson = value;
                RaisePropertyChanged();
            }
        }

        private AsyncCustomCommand? _addCommand;
        public ICommand ButtonAddClick => _addCommand ??= new AsyncCustomCommand(Add);

        private AsyncCustomCommand? _clearCommand;
        public ICommand ButtonClearClick => _clearCommand ??= new AsyncCustomCommand(Clear);

        private AsyncCustomCommand? _deleteCommand;
        public ICommand ButtonDeleteClick => _deleteCommand ??= new AsyncCustomCommand(Delete);

        private async Task Add(object o)
        {
            this.IsButtonEnabled = false;
            await Task.Delay(3000);

            this.Persons.Add(new Person() { Name = this.CurrentName, Surname = this.CurrentSurname });

            this.CurrentName = "";
            this.CurrentSurname = "";
            this.IsButtonEnabled = true;
        }

        private async Task Clear(object o)
        {
            this.IsButtonEnabled = false;
            await Task.Delay(3000);

            this.Persons.Clear();

            this.CurrentName = "";
            this.CurrentSurname = "";
            this.IsButtonEnabled = true;
        }

        private async Task Delete(object o)
        {
            this.IsButtonEnabled = false;
            await Task.Delay(3000);

            this.Persons.Remove(o as Person);

            this.CurrentName = "";
            this.CurrentSurname = "";
            this.IsButtonEnabled = true;
        }

        public event PropertyChangedEventHandler? PropertyChanged;
        private void RaisePropertyChanged([CallerMemberName] string propertyName = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
