#题目描述
 查找所有员工的last_name和first_name以及对应的dept_name，也包括暂时没有分配部门的员工
 CREATE TABLE `departments` (
 `dept_no` char(4) NOT NULL,
 `dept_name` varchar(40) NOT NULL,
 PRIMARY KEY (`dept_no`));
 CREATE TABLE `dept_emp` (
 `emp_no` int(11) NOT NULL,
 `dept_no` char(4) NOT NULL,
 `from_date` date NOT NULL,
 `to_date` date NOT NULL,
 PRIMARY KEY (`emp_no`,`dept_no`));
 CREATE TABLE `employees` (
 `emp_no` int(11) NOT NULL,
 `birth_date` date NOT NULL,
 `first_name` varchar(14) NOT NULL,
 `last_name` varchar(16) NOT NULL,
 `gender` char(1) NOT NULL,
 `hire_date` date NOT NULL,
 PRIMARY KEY (`emp_no`));

 - SELECT e.last_name, e.first_name, dp.dept_name FROM employees AS e
   LEFT JOIN dept_emp AS d ON e.emp_no = d.emp_no
   LEFT JOIN departments AS dp ON d.dept_no = dp.dept_no;