# Write your MySQL query statement below
WITH temp AS
(
    SELECT
        *,
        DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
    FROM 
        Employee
)
SELECT 
    MAX(salary) AS SecondHighestSalary
FROM 
    temp
WHERE
    rnk = 2;