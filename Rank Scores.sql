# Write your MySQL query statement below

Select S1.Score, (Select (count(distinct S2.Score)+1) from Scores S2 where S1.Score < S2.Score) AS Rank
From Scores S1
Order by Score DESC