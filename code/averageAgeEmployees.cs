using System;
using System.Collections.Generic;
using System.Linq;

namespace Solution
{
    public class Solution
    {
        // Method to calculate the average age of employees for each company
        public static Dictionary<string, int> AverageAgeForEachCompany(List<Employee> employees)
        {
            return employees
                .GroupBy(e => e.Company)  // Group employees by their company
                .OrderBy(g => g.Key)  // Sort the companies alphabetically
                .ToDictionary(
                    g => g.Key,  // The company name is the key
                    g => (int)Math.Round(g.Average(e => e.Age))  // Calculate the average age and round it at the end
                );
        }

        // Method to calculate the count of employees for each company
        public static Dictionary<string, int> CountOfEmployeesForEachCompany(List<Employee> employees)
        {
            return employees
                .GroupBy(emp => emp.Company) // Group by company
                .ToDictionary(
                    group => group.Key, // Key is the company name
                    group => group.Count() // Count the number of employees
                )
                .OrderBy(kv => kv.Key) // Sort by company name
                .ToDictionary(kv => kv.Key, kv => kv.Value); // Convert back to dictionary
        }

        // Method to find the oldest employee for each company
        public static Dictionary<string, Employee> OldestAgeForEachCompany(List<Employee> employees)
        {
            return employees
                .GroupBy(emp => emp.Company) // Group by company
                .ToDictionary(
                    group => group.Key, // Key is the company name
                    group => group.OrderByDescending(emp => emp.Age).First() // Get the oldest employee
                )
                .OrderBy(kv => kv.Key) // Sort by company name
                .ToDictionary(kv => kv.Key, kv => kv.Value); // Convert back to dictionary
        }

        public static void Main()
        {   
            int countOfEmployees = int.Parse(Console.ReadLine()); // Read number of employees
            
            var employees = new List<Employee>();
            
            // Read employee data
            for (int i = 0; i < countOfEmployees; i++)
            {
                string str = Console.ReadLine();
                string[] strArr = str.Split(' ');
                employees.Add(new Employee { 
                    FirstName = strArr[0], 
                    LastName = strArr[1], 
                    Company = strArr[2], 
                    Age = int.Parse(strArr[3]) 
                });
            }
            
            // Print average age for each company
            foreach (var emp in AverageAgeForEachCompany(employees))
            {
                Console.WriteLine($"The average age for company {emp.Key} is {emp.Value}");
            }
            
            // Print count of employees for each company
            foreach (var emp in CountOfEmployeesForEachCompany(employees))
            {
                Console.WriteLine($"The count of employees for company {emp.Key} is {emp.Value}");
            }
            
            // Print the oldest employee for each company
            foreach (var emp in OldestAgeForEachCompany(employees))
            {
                Console.WriteLine($"The oldest employee of company {emp.Key} is {emp.Value.FirstName} {emp.Value.LastName} having age {emp.Value.Age}");
            }
        }
    }
    
    public class Employee
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public int Age { get; set; }
        public string Company { get; set; }
    }
}
