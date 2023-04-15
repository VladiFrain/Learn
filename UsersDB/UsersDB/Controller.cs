using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UsersDB
{
    internal class Controller
    {
        public static void Start()
        {
            bool stop = false;
            while (!stop)
            {
                Console.WriteLine();
                Console.WriteLine("Выберите функцию:");
                Console.WriteLine("1. Показать пользователей");
                Console.WriteLine("2. Показать команды");
                Console.WriteLine("3. Создать новую команду");
                Console.WriteLine("4. Удалить команду");
                Console.WriteLine("5. Зарегистрировать нового пользователя");
                Console.WriteLine("6. Удалить первого пользователя");
                Console.WriteLine("7. Удалить пользователя по имени");
                Console.WriteLine("8. Изменить имя пользователя");
                Console.WriteLine("9. Выход");
                int select = int.Parse(Console.ReadLine());
                switch (select)
                {
                    case 1:
                        Console.Clear();
                        PrintUsers();
                        break;
                    case 2:
                        Console.Clear();
                        PrintTeams();
                        break;
                    case 3:
                        Console.Clear();
                        AddTeam();
                        break;
                    case 4:
                        Console.Clear();
                        DeleteTeam();
                        break;
                    case 5:
                        Console.Clear();
                        RegisterUser();
                        break;
                    case 6:
                        Console.Clear();
                        User.DeleteFirstUser();
                        break;
                    case 7:
                        DeleteUser();
                        Console.Clear();
                        break;
                    case 8:
                        EditUser();
                        break;
                    case 9:
                        stop = true;
                        break;
                    default:
                        Console.Clear();
                        Console.WriteLine("Не верный выбор!");
                        break;
                }
            }
        }

        internal static void RegisterUser()
        {
            Console.Write("Введите имя: ");
            string? name = Console.ReadLine();

            Console.Write("Введите возраст: ");
            int age = int.Parse(Console.ReadLine());

            PrintTeams();

            Console.Write("Введите номер команды: ");
            int team = int.Parse(Console.ReadLine());

            User.RegisterUser(name, age, team);
        }

        internal static void EditUser()
        {
            Console.Write("Введите имя: ");
            string? name = Console.ReadLine();
            Console.Write("Введите новое имя: ");
            string? newName = Console.ReadLine();

            try
            {
                User.Edit(name, newName);
            }
            catch (IndexOutOfRangeException)
            {
                Console.WriteLine("Такого пользователя нет!");
            }
        }

        internal static void DeleteUser()
        {
            using ApplicationContext db = new();
            Console.Write("Введите имя: ");
            string? name = Console.ReadLine();

            User.DeleteUser(name);
        }

        internal static void PrintUsers()
        {
            var users = User.PrintUsers();

            Console.WriteLine("Users list:");
            foreach (var user in users)
            {
                Console.WriteLine(user);
            }
        }

        internal static void AddTeam()
        {
            Console.Write("Введите название: ");
            string? name = Console.ReadLine();

            Team.AddTeam(name);
        }

        internal static void DeleteTeam()
        {
            using ApplicationContext db = new();
            PrintTeams();
            Console.Write("Введите номер команды: ");
            int id = int.Parse(Console.ReadLine());
            Console.WriteLine("Удаление команды так же удалит всех пользователей, которые входят в эту команду!");
            Console.WriteLine("Вы уверены? (y/n)");
            bool delete;
            if (Console.ReadLine() == "y")
            {
                delete = true;
            }
            else
            {
                delete = false;
            }

            Console.WriteLine(Team.DeleteTeam(id, delete));
        }

        internal static void PrintTeams()
        {
            var teams = Team.PrintTeams();
            Console.WriteLine("Teams list:");
            foreach (var team in teams)
            {
                Console.WriteLine(team);
            }
        }
    }
}
