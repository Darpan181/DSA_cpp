# Write your MySQL query statement below
WITH temp AS 
(
    SELECT 
        class,
        COUNT(class) AS cnt
    FROM 
        Courses
    GROUP BY
        class
)
SELECT
    class
FROM 
    temp
WHERE
     cnt >= 5;
