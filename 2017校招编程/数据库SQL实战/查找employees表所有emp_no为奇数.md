# 题目描述
  查找employees表所有emp_no为奇数，且last_name不为Mary的员工信息，并按照hire_date逆序排列
  CREATE TABLE `employees` (
  `emp_no` int(11) NOT NULL,
  `birth_date` date NOT NULL,
  `first_name` varchar(14) NOT NULL,
  `last_name` varchar(16) NOT NULL,
  `gender` char(1) NOT NULL,
  `hire_date` date NOT NULL,
  PRIMARY KEY (`emp_no`));

 - select * from employees e
   where e.last_name <> 'Mary'
   and e.emp_no % 2 =1
   order by e.hire_date DESC;