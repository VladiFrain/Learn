using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UsersDB
{
    internal class Team
    {
        public int Id { get; set; }

        public string Name { get; set; }

        public List<User> Users { get; set; }

        public override string? ToString()
        {
            var users = string.Empty;
            foreach (var user in Users)
            {
                users += user.Name + " ";
            }
            return $"\t{Id} - {Name}\n\t\t{users}";
        }

        internal static void AddTeam(string name)
        {
            using ApplicationContext db = new ApplicationContext();
            Team newTeam = new() { Name = name };

            db.Teams.Add(newTeam);
            db.SaveChanges();
        }

        internal static string DeleteTeam(int id, bool delete)
        {
            using ApplicationContext db = new();
            var teams = db.Teams.ToList();
            foreach (var team in teams)
            {
                if (team.Id == id)
                {
                    if (delete)
                    {
                        db.Remove(team);
                        db.SaveChanges();

                        return "Удалено!";
                    }
                }
            }

            return "Команда не найдена!";
        }

        internal static List<Team> PrintTeams()
        {
            using ApplicationContext db = new();
            var teams = db.Teams.Include(p => p.Users).ToList();

            return teams;
        }
    }
}
