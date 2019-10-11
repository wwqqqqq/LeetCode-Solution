Select
    IFNULL(
        (Select distinct Salary
         From Employee
         Order by Salary DESC
         Limit 1 offset 1),
        NULL
    )
SecondHighestSalary;
