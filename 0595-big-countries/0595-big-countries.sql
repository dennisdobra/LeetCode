/* Write your PL/SQL query statement below */
SELECT name "name", population "population", area "area"
FROM World
WHERE area >= 3000000 OR population >= 25000000;