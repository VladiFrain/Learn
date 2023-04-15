using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UsersDB
{
    internal class User
    {
        public int Id { get; set; }

        [MaxLength(10)]
        public string? Name { get; set; }

        [MaxLength(2)]
        public int Age { get; set; }

        public int TeamId { get; set; }

        public Team Team { get; set; }

        public override string? ToString()
        {
            return $"Имя: {Name}\tВозраст: {Age}\tНазвание команды: {Team.Name}";
        }

        internal static void RegisterUser(string name, int age, int team)
        {
            using ApplicationContext db = new ApplicationContext();
            User newUser = new() { Name = name, Age = age, TeamId = team };

            db.Users.Add(newUser);
            db.SaveChanges();
        }

        internal static void Edit(string name, string newName)
        {
            using ApplicationContext db = new();

            var users = db.Users.Where(p => p.Name == name).ToArray();

            if (users.Length > 0)
            {
                var user = users[0];

                user.Name = newName;

                db.SaveChanges();
            }
            else
            {
                throw new IndexOutOfRangeException();
            }
        }

        internal static void DeleteFirstUser()
        {
            using ApplicationContext db = new();
            db.Remove(db.Users.First());
            db.SaveChanges();
        }

        internal static void DeleteUser(string name)
        {
            using ApplicationContext db = new();
            var users = db.Users.ToList();
            foreach (var user in users)
            {
                if (user.Name == name)
                {
                    db.Remove(user);
                    db.SaveChanges();
                }
            }
        }

        internal static List<User> PrintUsers()
        {
            using ApplicationContext db = new();
            var users = db.Users.Include(p => p.Team).ToList();

            return users;
        }
    }
}
