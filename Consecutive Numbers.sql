# Write your MySQL query statement below
select distinct log1.Num as ConsecutiveNums from (Logs as log1, Logs as log2, Logs as log3)
where log1.Id + 1 = log2.Id and log2.Id + 1 = log3.Id 
  and log1.Num = log2.Num and log2.Num = log3.Num;