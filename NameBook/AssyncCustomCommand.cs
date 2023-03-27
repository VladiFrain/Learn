using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace AsyncCustomCommand
{
    internal class AsyncCustomCommand : ICommand
    {
        protected readonly Predicate<object> _canExecute;
        protected Func<object, Task> _asyncExecute;

        public AsyncCustomCommand(Func<object, Task> execute)
            : this(execute, null)
        {
        }

        public AsyncCustomCommand(Func<object, Task> asyncExecute, Predicate<object> canExecute)
        {
            _asyncExecute = asyncExecute;
            _canExecute = canExecute;
        }

        public event EventHandler CanExecuteChanged
        {
            add => CommandManager.RequerySuggested += value;
            remove => CommandManager.RequerySuggested -= value;
        }

        public bool CanExecute(object parameter)
        {
            if (_canExecute == null)
            {
                return true;
            }

            return _canExecute(parameter);
        }

        public async void Execute(object parameter)
        {
            await ExecuteAsync(parameter);
        }

        protected virtual async Task ExecuteAsync(object parameter)
        {
            await _asyncExecute(parameter);
        }
    }
}
