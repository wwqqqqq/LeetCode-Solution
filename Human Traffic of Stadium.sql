# Write your MySQL query statement below
SELECT DISTINCT s1.* FROM stadium as s1, stadium as s2, stadium as s3
WHERE s1.people >= 100 and s2.people >= 100 and s3.people >= 100
and (
    (s1.id + 1 = s2.id and s2.id + 1 = s3.id) or
    (s1.id + 1 = s3.id and s2.id + 1 = s1.id) or
    (s2.id + 1 = s3.id and s3.id + 1 = s1.id)
)
order by s1.id;