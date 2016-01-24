-- phpMyAdmin SQL Dump
-- version 4.2.11
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jan 16, 2016 at 05:08 PM
-- Server version: 5.6.21
-- PHP Version: 5.6.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `attendance`
--

-- --------------------------------------------------------

--
-- Table structure for table `COM_401`
--

CREATE TABLE IF NOT EXISTS `COM_401` (
  `username` varchar(30) NOT NULL,
  `date` date NOT NULL,
  `present` tinyint(1) NOT NULL DEFAULT '1',
  `MC_OD` int(11) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `COM_401`
--

INSERT INTO `COM_401` (`username`, `date`, `present`, `MC_OD`) VALUES
('coe12b007', '2015-11-08', 1, 0),
('coe12b007', '2015-11-09', 1, 0),
('coe12b007', '2015-11-10', 1, 0),
('coe12b007', '2015-11-11', 1, 0),
('coe12b007', '2015-11-13', 1, 0),
('coe12b014', '2015-11-08', 1, 0),
('coe12b014', '2015-11-09', 1, 0),
('coe12b014', '2015-11-10', 0, 0),
('coe12b014', '2015-11-11', 1, 0),
('coe12b014', '2015-11-13', 0, 0),
('coe12b015', '2015-11-08', 0, 0),
('coe12b015', '2015-11-09', 1, 1),
('coe12b015', '2015-11-10', 1, 0),
('coe12b015', '2015-11-11', 1, 0),
('coe12b015', '2015-11-13', 1, 0);

-- --------------------------------------------------------

--
-- Table structure for table `courses`
--

CREATE TABLE IF NOT EXISTS `courses` (
  `course_id` varchar(10) NOT NULL,
  `course_name` varchar(25) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `courses`
--

INSERT INTO `courses` (`course_id`, `course_name`) VALUES
('COM_401', 'Simulation & Modelling'),
('ELE_401', 'Embedded Systems'),
('INT_401', 'Mini Project'),
('MAN_401', 'Professional Ethics');

-- --------------------------------------------------------

--
-- Table structure for table `ELE_401`
--

CREATE TABLE IF NOT EXISTS `ELE_401` (
  `username` varchar(30) NOT NULL,
  `date` date NOT NULL,
  `present` tinyint(1) NOT NULL DEFAULT '1',
  `MC_OD` int(11) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ELE_401`
--

INSERT INTO `ELE_401` (`username`, `date`, `present`, `MC_OD`) VALUES
('coe12b007', '2015-11-08', 1, 0),
('coe12b007', '2015-11-09', 1, 0),
('coe12b007', '2015-11-10', 1, 0),
('coe12b007', '2015-11-11', 1, 0),
('coe12b007', '2015-11-13', 1, 0),
('coe12b007', '2015-11-17', 1, 0),
('coe12b007', '2015-11-18', 1, 0),
('coe12b014', '2015-11-08', 1, 0),
('coe12b014', '2015-11-09', 1, 0),
('coe12b014', '2015-11-10', 0, 0),
('coe12b014', '2015-11-11', 1, 0),
('coe12b014', '2015-11-13', 0, 0),
('coe12b014', '2015-11-17', 1, 0),
('coe12b014', '2015-11-18', 1, 0),
('coe12b015', '2015-11-08', 0, 0),
('coe12b015', '2015-11-09', 0, 0),
('coe12b015', '2015-11-10', 1, 0),
('coe12b015', '2015-11-11', 0, 0),
('coe12b015', '2015-11-13', 1, 0),
('coe12b015', '2015-11-17', 1, 0),
('coe12b015', '2015-11-18', 1, 0),
('edm12b014', '2015-11-08', 1, 0),
('edm12b014', '2015-11-09', 1, 0),
('edm12b014', '2015-11-10', 1, 0),
('edm12b014', '2015-11-11', 1, 0),
('edm12b014', '2015-11-13', 0, 0),
('edm12b014', '2015-11-17', 1, 0),
('edm12b014', '2015-11-18', 1, 0),
('edm12b031', '2015-11-08', 1, 0),
('edm12b031', '2015-11-09', 1, 0),
('edm12b031', '2015-11-10', 0, 0),
('edm12b031', '2015-11-11', 0, 0),
('edm12b031', '2015-11-13', 1, 0),
('edm12b031', '2015-11-17', 1, 0),
('edm12b031', '2015-11-18', 1, 0);

-- --------------------------------------------------------

--
-- Table structure for table `INT_401`
--

CREATE TABLE IF NOT EXISTS `INT_401` (
  `username` varchar(30) NOT NULL,
  `date` date NOT NULL,
  `present` tinyint(1) NOT NULL DEFAULT '1',
  `MC_OD` int(11) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `INT_401`
--

INSERT INTO `INT_401` (`username`, `date`, `present`, `MC_OD`) VALUES
('edm12b014', '2015-11-08', 1, 0),
('edm12b014', '2015-11-09', 1, 0),
('edm12b014', '2015-11-10', 1, 0),
('edm12b014', '2015-11-11', 1, 0),
('edm12b014', '2015-11-13', 0, 0),
('edm12b031', '2015-11-08', 1, 0),
('edm12b031', '2015-11-09', 1, 0),
('edm12b031', '2015-11-10', 0, 0),
('edm12b031', '2015-11-11', 0, 0),
('edm12b031', '2015-11-13', 1, 0);

-- --------------------------------------------------------

--
-- Table structure for table `login`
--

CREATE TABLE IF NOT EXISTS `login` (
  `username` varchar(20) NOT NULL,
  `name` varchar(30) NOT NULL,
  `password` varchar(20) NOT NULL,
  `admin` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `login`
--

INSERT INTO `login` (`username`, `name`, `password`, `admin`) VALUES
('admin_ELE_401', 'Admin ELE 401', '401', 1),
('coe12b007', 'T. Iniyai', 'iniyai', 0),
('coe12b014', 'Medha Vasishth', 'medha', 0),
('coe12b015', 'Nada Abdul Majeed Pulath', 'nada', 0),
('edm12b014', 'Sravana Chandra', 'sravana', 0),
('edm12b031', 'Anusha', 'anusha', 0);

-- --------------------------------------------------------

--
-- Table structure for table `MAN_401`
--

CREATE TABLE IF NOT EXISTS `MAN_401` (
  `username` varchar(30) NOT NULL,
  `date` date NOT NULL,
  `present` tinyint(1) NOT NULL DEFAULT '1',
  `MC_OD` int(11) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `MAN_401`
--

INSERT INTO `MAN_401` (`username`, `date`, `present`, `MC_OD`) VALUES
('coe12b007', '2015-11-08', 1, 0),
('coe12b007', '2015-11-09', 1, 0),
('coe12b007', '2015-11-10', 1, 0),
('coe12b007', '2015-11-11', 1, 0),
('coe12b007', '2015-11-13', 1, 0),
('coe12b014', '2015-11-08', 1, 0),
('coe12b014', '2015-11-09', 1, 0),
('coe12b014', '2015-11-10', 0, 0),
('coe12b014', '2015-11-11', 1, 0),
('coe12b014', '2015-11-13', 0, 0),
('coe12b015', '2015-11-08', 0, 0),
('coe12b015', '2015-11-09', 0, 0),
('coe12b015', '2015-11-10', 1, 0),
('coe12b015', '2015-11-11', 1, 0),
('coe12b015', '2015-11-13', 1, 0),
('edm12b014', '2015-11-08', 1, 0),
('edm12b014', '2015-11-09', 1, 0),
('edm12b014', '2015-11-10', 1, 0),
('edm12b014', '2015-11-11', 1, 0),
('edm12b014', '2015-11-13', 0, 0),
('edm12b031', '2015-11-08', 1, 0),
('edm12b031', '2015-11-09', 1, 0),
('edm12b031', '2015-11-10', 0, 0),
('edm12b031', '2015-11-11', 0, 0),
('edm12b031', '2015-11-13', 1, 0);

-- --------------------------------------------------------

--
-- Table structure for table `MC_request`
--

CREATE TABLE IF NOT EXISTS `MC_request` (
  `username` varchar(20) NOT NULL,
  `date` date NOT NULL,
  `course_id` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `MC_request`
--

INSERT INTO `MC_request` (`username`, `date`, `course_id`) VALUES
('coe12b014', '2015-11-09', 'MAN_401'),
('coe12b014', '2015-11-11', 'ELE_401'),
('coe12b015', '2015-10-06', 'ELE_401'),
('coe12b015', '2015-10-06', 'MAN_401'),
('coe12b015', '2015-11-05', 'ELE_411'),
('coe12b015', '2015-11-10', 'ELE_411');

-- --------------------------------------------------------

--
-- Table structure for table `OD_request`
--

CREATE TABLE IF NOT EXISTS `OD_request` (
  `username` varchar(20) NOT NULL,
  `date` date NOT NULL,
  `course_id` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `OD_request`
--

INSERT INTO `OD_request` (`username`, `date`, `course_id`) VALUES
('coe12b015', '2015-11-05', 'ELE_411');

-- --------------------------------------------------------

--
-- Table structure for table `student`
--

CREATE TABLE IF NOT EXISTS `student` (
  `userid` int(11) NOT NULL,
  `rollno` varchar(30) NOT NULL,
  `course_id1` varchar(10) NOT NULL,
  `course_id2` varchar(10) NOT NULL,
  `course_id3` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `student`
--

INSERT INTO `student` (`userid`, `rollno`, `course_id1`, `course_id2`, `course_id3`) VALUES
(1, 'coe12b007', 'ELE_401', 'MAN_401', 'COM_401'),
(2, 'coe12b014', 'ELE_401', 'MAN_401', 'COM_401'),
(3, 'coe12b015', 'ELE_401', 'MAN_401', 'COM_401'),
(4, 'edm12b014', 'ELE_401', 'MAN_401', 'INT_401'),
(5, 'edm12b031', 'ELE_401', 'MAN_401', 'INT_401');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `COM_401`
--
ALTER TABLE `COM_401`
 ADD PRIMARY KEY (`username`,`date`);

--
-- Indexes for table `courses`
--
ALTER TABLE `courses`
 ADD PRIMARY KEY (`course_id`);

--
-- Indexes for table `ELE_401`
--
ALTER TABLE `ELE_401`
 ADD PRIMARY KEY (`username`,`date`);

--
-- Indexes for table `INT_401`
--
ALTER TABLE `INT_401`
 ADD PRIMARY KEY (`username`,`date`);

--
-- Indexes for table `login`
--
ALTER TABLE `login`
 ADD PRIMARY KEY (`username`);

--
-- Indexes for table `MAN_401`
--
ALTER TABLE `MAN_401`
 ADD PRIMARY KEY (`username`,`date`);

--
-- Indexes for table `MC_request`
--
ALTER TABLE `MC_request`
 ADD PRIMARY KEY (`username`,`date`,`course_id`);

--
-- Indexes for table `OD_request`
--
ALTER TABLE `OD_request`
 ADD PRIMARY KEY (`username`,`date`,`course_id`);

--
-- Indexes for table `student`
--
ALTER TABLE `student`
 ADD PRIMARY KEY (`rollno`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
