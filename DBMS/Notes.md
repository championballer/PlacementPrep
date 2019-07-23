## DBMS

### 1. SQL (Nested Queries)	
### 2. MongoDB
### 3. SQL vs NOSQL
### 4. Indexing, B Trees
### 5. Schedules and Transactions (Basic)
### 6. Normalisation
### 7. ER diagram
### 8. Joins

## Important Links and Repos
1. 

## Points 
1. SQL

	Note: '=' is used when we need to compare with one value, whereas in is used when we need to check or compare between multiple values in where.<break>
	Note: The attribute used to groupby is the only one which can be mentioned in its select along with aggregate functions applied on any other attribute of the table. Having clause is used with group by rather than where. Having applies condition per group rather than the whole table.
	Note: We can limit the return values from a query using limit keyword
	Note: Distinct will come in paranthesis while counting.
	Aggregation functions : MAX, MIN, COUNT, AVG, SUM 
		Query : select max(salary) from emp;
			select count(distinct salary) from emp;
			select count(*) from emp;
			
	Nested Query/ Subqueries: A query operating on the solution of another query. Breaking the problem into different queries, and how to operate with different answers. 
		1. Display the employee's name whose salary is maximum
			select e_name from emp where salary=(select max(salary) from emp));
		2. Display the second max salary 
			select max(salary) from emp where salary<>(select max(salary) from emp));
		3. Display the employee name with second max salary
			select e_name from emp where salary= (select max(salary) from emp where salary<>(select max(salary) from emp)));
		4. Display dept wise max salary 
			select max(salary) from emp group by dept;
		5. Display all dept. names along with no. of employees working in that department
			select count(dept) from emp group by dept;
		6. Display dept names where number of employees is less than 2
			select dept,count(dept) from emp group by dept having count(dept)<2;
		7. Display names of employees who are working in departments with more than or equal to 2 employees
			select name from emp where dept in (select dept from emp group by dept having count(dept)>=2);
		8. Display department wise salary and the name of the employee taking that salary
			 select name,dept,salary from emp where dept in (select dept from emp group by dept) and salary in (select max(salary) from emp group by dept) ;
		9. Display name of employees working on a project(project table has e_id)
			select name from emp where id in ( select distinct e_id from project);
			
