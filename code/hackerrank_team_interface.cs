using System;

namespace Solution
{
    public class Team
    {
        public string teamName;
        public int noOfPlayers;

        // Constructor
        public Team(string teamName, int noOfPlayers)
        {
            this.teamName = teamName;
            this.noOfPlayers = noOfPlayers;
        }

        // AddPlayer method
        public void AddPlayer(int count)
        {
            noOfPlayers += count;
        }

        // RemovePlayer method
        public bool RemovePlayer(int count)
        {
            if (noOfPlayers - count < 0)
            {
                return false;
            }
            noOfPlayers -= count;
            return true;
        }
    }

    public class Subteam : Team
    {
        // Constructor
        public Subteam(string teamName, int noOfPlayers) : base(teamName, noOfPlayers) { }

        // ChangeTeamName method
        public void ChangeTeamName(string name)
        {
            teamName = name;
        }
    }

    class Solution
    {
        static void Main(string[] args)
        {
            if (!typeof(Subteam).IsSubclassOf(typeof(Team)))
            {
                throw new Exception("Subteam class should inherit from Team class");
            }

            // Read initial input
            String str = Console.ReadLine();
            String[] strArr = str.Split();
            string initialName = strArr[0];
            int count = Convert.ToInt32(strArr[1]);

            // Create Subteam object
            Subteam teamObj = new Subteam(initialName, count);
            Console.WriteLine("Team " + teamObj.teamName + " created");

            // Read and process AddPlayer input
            str = Console.ReadLine();
            count = Convert.ToInt32(str);
            Console.WriteLine("Current number of players in team " + teamObj.teamName + " is " + teamObj.noOfPlayers);
            teamObj.AddPlayer(count);
            Console.WriteLine("New number of players in team " + teamObj.teamName + " is " + teamObj.noOfPlayers);

            // Read and process RemovePlayer input
            str = Console.ReadLine();
            count = Convert.ToInt32(str);
            Console.WriteLine("Current number of players in team " + teamObj.teamName + " is " + teamObj.noOfPlayers);
            var res = teamObj.RemovePlayer(count);
            if (res)
            {
                Console.WriteLine("New number of players in team " + teamObj.teamName + " is " + teamObj.noOfPlayers);
            }
            else
            {
                Console.WriteLine("Number of players in team " + teamObj.teamName + " remains same");
            }

            // Read and process ChangeTeamName input
            str = Console.ReadLine();
            teamObj.ChangeTeamName(str);
            Console.WriteLine("Team name of team " + initialName + " changed to " + teamObj.teamName);
        }
    }
}
