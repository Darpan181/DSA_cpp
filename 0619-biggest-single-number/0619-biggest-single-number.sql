# Write your MySQL query statement below
WITH temp AS
(
    SELECT
        num,
        COUNT(num) AS cnt
    FROM 
        MyNumbers
    GROUP BY
        num
)
SELECT
    MAX(num) AS num
FROM 
    temp
WHERE
    cnt = 1;