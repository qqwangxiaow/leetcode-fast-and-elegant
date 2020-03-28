#offset skit n tips
select (select distinct Salary from Employee order by Salary DESC limit 1 offset 1) as SecondHighestSalary