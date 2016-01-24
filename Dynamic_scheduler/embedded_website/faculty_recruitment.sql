-- phpMyAdmin SQL Dump
-- version 3.4.10.1deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: May 31, 2014 at 11:39 AM
-- Server version: 5.5.37
-- PHP Version: 5.3.10-1ubuntu3.11

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `faculty_recruitment`
--

-- --------------------------------------------------------

--
-- Table structure for table `advt_number`
--

CREATE TABLE IF NOT EXISTS `advt_number` (
  `advt_no` varchar(200) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `advt_number`
--

INSERT INTO `advt_number` (`advt_no`) VALUES
('1234');

-- --------------------------------------------------------

--
-- Table structure for table `educational_qualifications`
--

CREATE TABLE IF NOT EXISTS `educational_qualifications` (
  `userid` int(11) NOT NULL,
  `sno` int(11) NOT NULL,
  `degree` varchar(100) NOT NULL,
  `degreetype` tinyint(3) unsigned DEFAULT NULL COMMENT '0 - others, 1 - Bachelors, 2 - Masters, 3 - Doctoral',
  `insti` varchar(100) NOT NULL,
  `yoe` text NOT NULL,
  `yol` text NOT NULL,
  `percent` double NOT NULL,
  PRIMARY KEY (`userid`,`sno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `educational_qualifications`
--

INSERT INTO `educational_qualifications` (`userid`, `sno`, `degree`, `degreetype`, `insti`, `yoe`, `yol`, `percent`) VALUES
(4, 1, 'hb', NULL, 'hb', 'bh', 'bh', 0),
(6, 1, 'a', NULL, 'q', 'w', 'e', 0),
(6, 2, 'ty', NULL, 'u', 'i', 'op', 0),
(6, 3, 'q', NULL, 'q', 'q', 'q', 0),
(6, 4, 'q', NULL, 'q', 'q', 'q', 0),
(6, 5, 'q', NULL, 'q', 'q', 'q', 0),
(7, 1, 'y', NULL, 'q', 'w', 'e', 0),
(7, 2, 'undefined', NULL, 'undefined', 'undefined', 'undefined', 0),
(9, 1, 'be', NULL, 'mgr', '1998', '2002', 80),
(10, 1, 'ms', NULL, 'iitm', '2005', '2007', 88),
(10, 2, 'phd', NULL, 'iitm', '2007', '2012', 90),
(14, 1, 'hjbhbh', NULL, 'bhbh', '1992', '1993', 90),
(14, 2, 'njj', NULL, 'jnhjn', '98', '998', 98),
(15, 1, 'j', 1, 'J', '1', '1', 1),
(16, 1, 'Bachelors', NULL, 'IIITDM', '2010', '2014', 90),
(16, 2, 'Masters', NULL, 'Stanford', '2015', '2017', 4),
(16, 3, 'PhD', NULL, 'CMU', '2017', '2021', 100),
(23, 1, 'jnj', NULL, 'hhbh', 'bh', 'hb', 123),
(23, 2, 'jnhb', NULL, 'bhb', 'bhb', 'bh', 12),
(24, 1, 'fkwn', 1, 'skfks`', '2014', '2016', 90),
(24, 2, 'jhajsha', 2, 'khbks', '8778', '8769', 84),
(26, 1, 'njsjncj', 3, 'IIT', '19390', '194p', 95),
(27, 1, 'B.E', 1, 'IIITd&m', '2011', '2015', 95),
(32, 1, 'B.Tech', 1, 'iiit', '2011', 'dfsa', 200),
(35, 1, 'B.Tech', 1, 'iiitd&m kancheepuram', '2011', '2015', 7),
(37, 1, 'asdfaf', 1, 'asdfasdf', '3422', '234244', 245),
(39, 1, 'hbsh', 1, 'kjdfnks', '8766', '9876', 9878),
(45, 1, 'BTECH', 2, 'IIITDM', '2011', '2000', 99),
(54, 1, 'Btech', 1, 'iii', '2010', '2014', 89),
(54, 2, 'vhvb', 2, 'vnbv', '8768', '7687', 67),
(55, 1, 'khjkhkjh', 1, 'hkjhkjh', '8789', '9809', 98),
(56, 1, 'hkjhjkh', 1, 'iyuiyui', '7678', '678', 67);

-- --------------------------------------------------------

--
-- Table structure for table `form1`
--

CREATE TABLE IF NOT EXISTS `form1` (
  `userid` int(11) NOT NULL,
  `post` varchar(50) DEFAULT NULL,
  `area` varchar(100) DEFAULT NULL,
  `researcharea` varchar(100) DEFAULT NULL,
  `adno` varchar(100) DEFAULT NULL,
  `name` varchar(50) DEFAULT NULL,
  `dob` date DEFAULT NULL,
  `nationality` varchar(50) DEFAULT NULL,
  `gender` varchar(10) DEFAULT NULL,
  `category` varchar(20) DEFAULT NULL,
  `categorycerti` varchar(100) DEFAULT NULL,
  `address` varchar(500) DEFAULT NULL,
  `permaddress` varchar(500) DEFAULT NULL,
  `fathername` varchar(50) DEFAULT NULL,
  `designation` varchar(100) DEFAULT NULL,
  `photo` varchar(100) DEFAULT NULL,
  `submitted` tinyint(11) DEFAULT NULL,
  `addr_mobile` varchar(50) DEFAULT NULL,
  `addr_email` varchar(50) DEFAULT NULL,
  `perm_mobile` varchar(50) DEFAULT NULL,
  `perm_email` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`userid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `form1`
--

INSERT INTO `form1` (`userid`, `post`, `area`, `researcharea`, `adno`, `name`, `dob`, `nationality`, `gender`, `category`, `categorycerti`, `address`, `permaddress`, `fathername`, `designation`, `photo`, `submitted`, `addr_mobile`, `addr_email`, `perm_mobile`, `perm_email`) VALUES
(6, 'Professor', 'Electronics', 'iijsdhgujf', NULL, 'hjknkjn', '2013-01-31', 'Indian', 'Female', 'ST', NULL, 'hchgv989', 'hgvjh', 'mn ,m', 'mnb m', NULL, 1, '9884699572', 'deepthireddy2309@gmail.com', '944', 'bhhjb'),
(7, 'Assistant Professor', 'Electronics', 'kjnjin', NULL, 'klnj', '0000-00-00', 'trfhtg', 'Female', 'SC', 'upload/7_categorycerti.pdf', '', '', 'klnjkn', 'jnjn', 'upload/7_photo.png', 0, '', '', '', ''),
(9, 'Assistant Professor', 'Computer Science', 'toc', NULL, 'Sadagopan', '1209-09-09', 'Indian', 'Male', 'Others', '', '1', '0', 'ns', 'ap68', 'upload/9_photo.jpg', 1, '09', 'sa', '1', '2'),
(10, 'Professor', 'Electronics', 'toc', NULL, 'sadagopan', '1981-10-31', 'indian', 'Male', 'Others', '', '1', '1', 'narasimhan', 'none', 'upload/10_photo.jpg', 1, '2', 'sada', '2', '1'),
(14, 'Professor', 'Computer Science', 'dsf', NULL, 'Anand', '1992-02-23', 'Indian', 'Male', 'Others', '', 'dfdsgsdgkjn ', 'dgff', 'sjdjsfn', 'jnkxvnjdvbsdkj', 'upload/14_photo.jpg', 1, '992', 'lkn kjn', ' km ', ' ,m m'),
(15, 'Assistant Professor', 'Mechanical', 'lknkjn', '1234', 'njknjnj', '0000-00-00', 'knjn', 'Female', 'Others', 'upload/15_categorycerti.pdf', 'kkjnkjn', 'njnk', 'mmlkm', 'jnkn', 'upload/15_photo.jpg', 0, '', 'sowmyajain@yaho', '', ''),
(16, 'Assistant Professor', 'Computer Science', 'Parallel Computing, Architecture, Data Structures & Algortihms', NULL, 'Deepthi Reddy', '1992-08-23', 'Indian', 'Female', 'ST', 'upload/16_categorycerti.pdf', '4-6-154, Koti, Sultan Bazar\r\nHyderabad, Andhra Pradesh\r\nPin:500027', '4-6-154, Koti, Sultan Bazar\r\nHyderabad, Andhra Pradesh\r\nPin:500027', 'Venkat Reddy', '-NIL-', 'upload/16_photo.jpg', 1, '+919551954812', 'coe10b008@iiitdm.ac.in', '+919551954812', 'coe10b008@iiitdm.ac.in'),
(23, 'Assistant Professor', 'Computer Science', 'jnjnj', NULL, 'jnjn', '0000-00-00', 'njn', 'Female', 'ST', 'upload/23_categorycerti.pdf', 'km jm', 'kmjkm', 'hhj', 'jhj', 'upload/23_photo.jpg', 1, 'jnjnj', 'sowm@jnjf.com', 'kmkmk', ''),
(24, 'Professor', 'Computer Science', 'jhasbda', '1234', 'Madhu Iluri', '1995-03-06', 'Indian', 'Female', 'Others', '', 'iiit d&m kancheepuram\r\njasmine ', 'lkdjajksdbdjsab\r\nguntur', 'daddy ', 'hbsrkw', '', 1, '917401336509', 'coe11b012@iiitdm.ac.in', '7401336509', ''),
(25, 'Professor', 'Computer Science', 'soft engg', '1234', 'VIJAY', '1992-07-20', '', 'Male', 'Others', '', '', '', '', '', 'upload/25_photo.jpg', 0, 'jkjskd', '', '', ''),
(26, 'Professor', 'Computer Science', 'sjdjndkck', '1234', 'Monika Achanta', '1994-08-09', 'Indian', 'Female', 'Others', '', 'iitd&m kancheepuram,melekottaiyur', 'knsnsnkslxlsm c', 'Vishnu Murthy', 'kkxkm n jo', '', 1, '9445419520', 'achantamounica@gmail.com', '9445419520', ''),
(27, 'Professor', 'Computer Science', 'graphs', '1234', 'Manogna Vennamaneni', '2015-02-02', 'Indian', 'Female', 'Others', '', 'Room no:324,jasmine hostel,IIITd&m kancheepuram\r\nvandalur to kelambakkam road,kandigai', '', 'VBKR', 'Manager', 'upload/27_photo.jpg', 1, '917299417911', 'manogna1409@gmail.com', '', ''),
(29, 'Professor', 'Computer Science', 'bhjkhjnkj', '1234', 'dddgdr', '0004-05-05', 'kjjkjk', 'Male', 'Others', '', 'jh', '6565466', 'hhvjghh', 'hfgfghfhggf', '', 0, 'hdhdh', 'hvh', 'vgvhgffh', ''),
(30, 'Professor', '', '', '1234', '', '0000-00-00', '', '', '', '', '', '', '', '', '', 0, '', '', '', ''),
(32, 'Professor', 'Computer Science', 'Machine Learning', '1234', 'Kuladeep', '0000-00-00', 'Indian', 'Male', 'Others', '', 'Anand, IIITD&M', '', '', '', 'upload/32_photo.jpg', 0, '9843437987374826932', '', '', ''),
(35, 'Professor', 'Computer Science', 'web design', '1234', 'dellhp', '1992-05-09', 'indian', 'Male', 'SC', 'upload/35_categorycerti.pdf', 'room no:923, new hostel ,iiitdm kancheepuram', 'room no:923, new hostel ,iiitdm kancheepuram', 'lenovo', 'toshiba', 'upload/35_photo.png', 0, '9442311234', 'coe11b011@iiitdm.ac.in', '9442311234', ''),
(37, 'Professor', 'Engineering Design', 'asdfsfsasdf', '1234', 'sai kumar', '0000-00-00', '123412341324', 'Male', 'Others', '', 'asdfqwer3233 adsf asd', 'asdfwer234232assdfsdfasdfwerwerwer', 'asdfasdf234234asdfasdf23423asdf2334', 'asdfasdf23423423asdfdsfasf', '', 0, 'qqwqw32234234jjj', 'bbbaasfasdf3dfasdf', '23423423423423asdfasdf234sdf', ''),
(39, 'Professor', 'Computer Science', 'jhasbda', '1234', 'hqhekq', '1995-06-03', 'j,adja', 'Female', 'Others', '', 'jhkdhsika', 'kadkja', 'jhabdjab', 'kadjqb', 'upload/39_photo.jpg', 1, 'adgjha', 'jabdka@jkdfskjd.com', 'sbfkjabka', ''),
(45, 'Assistant Professor', 'Mechanical', 'ENGINE', '1234', 'RAM NAIK', '1999-03-02', 'INDIAN', 'Male', 'ST', '', 'ARTS COLLEGE QUARTERS ,  Q-NO A-3', 'ARTS COLLEGE QUARTERS ,  Q-NO  A-3\r\n', 'YADAGIRI', 'MANAGER /11111', '', 0, '8122991076', 'coe11b017@iiitdm.ac.in', '8122991076', ''),
(50, '', '', '', '1234', '', '0000-00-00', '', '', '', '', '', '', '', '', '', 0, '', '', '', ''),
(54, 'Assistant Professor', 'Electronics', 'abc', '1234', 'xyz', '1993-10-02', 'Indian', 'Male', 'OBC', 'upload/54_categorycerti.pdf', 'hbhb', 'hk', 'hjkhkj', 'hmnbk', 'upload/54_photo.jpg', 1, '9999', 'bc@pqr.com', '999998', ''),
(55, 'Professor', 'Computer Science', 'jhkjhjkh', '1234', 'jkjklj', '2012-09-09', 'Indian', 'Male', 'Others', '', 'KJkljkljkljkljkl', 'ljkljkljkljklj', 'Ljlkjkljkl', 'ljkljkl', 'upload/55_photo.png', 1, '09890809', 'lhjhjkhjk@jhjhjk.clj', '8997897987', ''),
(56, 'Professor', 'Computer Science', 'jhjkhjk', '1234', 'kjhjkhkjhjk', '0000-00-00', 'jghjjkh', 'Male', 'Others', '', 'jkljkljkl', 'jhkkh', 'hkjhkj', 'hhkjhjkh', 'upload/56_photo.png', 1, 'jkljklj', 'hgjkhkjhkjh@kjkjkl.ckj', '7676786', '');

-- --------------------------------------------------------

--
-- Table structure for table `form2`
--

CREATE TABLE IF NOT EXISTS `form2` (
  `userid` int(11) NOT NULL,
  `intjournals3` int(11) DEFAULT NULL,
  `intjournalsoverall` int(11) DEFAULT NULL,
  `natjournals3` int(11) DEFAULT NULL,
  `natjournalsoverall` int(11) DEFAULT NULL,
  `intconf3` int(11) DEFAULT NULL,
  `intconfoverall` int(11) DEFAULT NULL,
  `natconf3` int(11) DEFAULT NULL,
  `natconfoverall` int(11) DEFAULT NULL,
  `publications` varchar(10000) DEFAULT NULL,
  `paper1` varchar(100) DEFAULT NULL,
  `paper2` varchar(100) DEFAULT NULL,
  `paper3` varchar(100) DEFAULT NULL,
  `submitted` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`userid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `form2`
--

INSERT INTO `form2` (`userid`, `intjournals3`, `intjournalsoverall`, `natjournals3`, `natjournalsoverall`, `intconf3`, `intconfoverall`, `natconf3`, `natconfoverall`, `publications`, `paper1`, `paper2`, `paper3`, `submitted`) VALUES
(6, 5, 5, 5, 65, 6, 6, 6, 6, '', '', '', '', 1),
(7, 7, 8, 1, 2, 3, 4, 5, 6, 'hghjhj', 'upload/7_paper1.pdf', 'upload/7_paper2.pdf', 'upload/7_paper3.pdf', 1),
(9, 1, 0, 1, 2, 3, 1, 1, 1, '', '', '', '', 1),
(10, 4, 4, 0, 0, 2, 2, 0, 0, '', 'upload/10_paper1.pdf', 'upload/10_paper2.pdf', '', 1),
(14, 8, 8, 8, 8, 8, 8, 8, 8, 'hjn b ', '', '', '', 1),
(16, 20, 40, 0, 0, 30, 60, 0, 0, 'polyamide 66/hectorite nanocomposites", in Composites Part B: Engineering, 42 (3),, 2011, 466-472\r\n    Arun Prakash N, Gnanamoorthy, R and Kamaraj "Microstructural Evolution and Mechanical Properteis of oil jet peened aluminium alloy,", in Materials & Design, 31 (9),, 2010, 4066-4075.\r\n    Finney Charles D, Gnanamoorthy R, Parag Ravindran "‘Rolling contact fatigue behavior of polyamide clay reinforced nanocomposite - Effect of Load and Speed’, .", in Wear , 269 (7-8),, 2010, pp. 565-571\r\n    Rajeesh K R, Gnanamoorthy, R and Velmurugan R "Effect of Humidity on the Indentation Hardness and Flexural Fatigue Behavior of Polyamide 6 Nanocomposite", in Mat. Sci. Eng A, A 527, 2010, 2826–2830\r\n    Ramkumar A, Gnanamoorthy R "Effect of nanoclay addition on the displacement-controlled Flexural Fatigue Behavior of a polymer, ", in J Mat Sci, 45 (15), , 2010, 4180-4187.\r\n    Rajeesh, Gnanamoorthy R, Velumurugan, "Effect of moisture content on tensile behaviour of polyamide 6 nanocomposites’", in , Proc of I Mech: J. Materials: Design & Applications, 4 (4), , 2010, 173-176.\r\n    Sahaya Grinspan and R Gnanamoorthy "Impact force of low velocity liquid droplets measured using piezo electric PVDF film’,", in Colloids & Surfaces A: Physiochemical and Engineering Aspects, , 356, (1-3) , 2010, 162-168\r\n    Arun Prakash N, Gnanamoorthy, R and Kamaraj "Dry sliding wear behavior of oil jet peened aluminum alloy, AA6063-t6’", in Proc. IMechE Pt J: J. Engg Tribology,, 224 (11), 2010, 1189-1196\r\n    Timmaraju V M, K Kannan, Gnanamoorthy R "Influence of organoclay on flexural fatigue behavior of polyamide 66/hectorite nanocomposites at laboratory condition", ", in Polymer Composites , 31 (11), 2010, pp. 1977-1986.\r\n    Ganesh Sundara Raman S, P Navaneethakrishnan, and R Gnanamoorthy "Influence of counterbody material on fretting wear behaviour of uncoated and diamond-like carbon-coated Ti-6Al-4V", in IMechE , 222, 2009,\r\n    Arun Prakash N, Gnanamoorthy, R and Kamaraj "Friction and wear behaviour of surface nanocrystallized Al alloy under dry lubricated conditions’", in Mat. Sci. Eng B, 168, 2009, 176-181\r\n    A Sahaya Grinspan and R Gnanamoorthy "Development of a Noovel Oil ', 'upload/16_paper1.pdf', 'upload/16_paper2.pdf', 'upload/16_paper3.pdf', 1),
(23, 4, 4, 4, 4, 4, 4, 4, 44, 'cv ghb jb ', '', '', '', 1),
(26, 5, 6, 1, 2, 5, 5, 4, 4, ' vlvl,mkhmkmkhmlhg,;g', '', '', '', 1),
(27, 1, 1, 1, 1, 1, 1, 1, 1, 'klfnwoiefbiepbfiwoebviqbviqebviqbvibqivbfqibfi', '', '', '', 1),
(39, 93, 868, 6, 878, 7878, 8778, 787, 7878, 'hdbfsbjsbjfbsj', '', '', '', 1),
(54, 5, 5, 6, 7, 3, 3, 1, 1, 'jhjkh', 'upload/54_paper1.pdf', 'upload/54_paper2.pdf', '', 1),
(55, 1, 1, 1, 1, 1, 1, 1, 1, '', '', '', '', 1),
(56, 3, 3, 3, 3, 3, 3, 3, 3, '', '', '', '', 1);

-- --------------------------------------------------------

--
-- Table structure for table `form3`
--

CREATE TABLE IF NOT EXISTS `form3` (
  `userid` int(11) NOT NULL,
  `undergrad` varchar(4) DEFAULT NULL,
  `postgrad` varchar(4) DEFAULT NULL,
  `doctoral` varchar(4) DEFAULT NULL,
  `research_deg` varchar(4) DEFAULT NULL,
  `courses_undergrad` varchar(10000) DEFAULT NULL,
  `courses_postgrad` varchar(10000) DEFAULT NULL,
  `wrkshps` varchar(10000) DEFAULT NULL,
  `patents` varchar(5000) DEFAULT NULL,
  `experience` varchar(10000) DEFAULT NULL,
  `memberships` varchar(5000) DEFAULT NULL,
  `awards` varchar(10000) DEFAULT NULL,
  `submitted` tinyint(1) DEFAULT '0',
  PRIMARY KEY (`userid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `form3`
--

INSERT INTO `form3` (`userid`, `undergrad`, `postgrad`, `doctoral`, `research_deg`, `courses_undergrad`, `courses_postgrad`, `wrkshps`, `patents`, `experience`, `memberships`, `awards`, `submitted`) VALUES
(6, '1', '6', '6', '6', '', '', '', '', '', '', '', 1),
(7, '', '5', '6', '4', '', 'Postgrad', '', '', '', '', '', 0),
(9, '0', '0', '0', '0', '', '', '', '', '', '', '', 1),
(10, '0', '0', '0', '0', '', '', '', '', '', '', '', 1),
(14, '6', '6', '6', '6', '', '', '', '', '', '', '', 1),
(15, '2', '5', '2', '2', 'kldknDLC', ',SMCN DMC', '', '', '', '', '', 1),
(16, '100', '10', '10', '20', '    Mechanical Design with Advanced Materials\r\n    Nanocompsoites - Product Design and Manufacturing\r\n    Surface Nanocrystallization - Novel Manufacturing Process Development\r\n    Engineering the Surfaces for Improved Performance\r\n    Fatigue and Fracture Mechanics of Advanced Engineering Materials\r\n    Tribo Characteristics of Biomaterials and Polymer Nano Composites', '    Mechanical Design with Advanced Materials\r\n    Nanocompsoites - Product Design and Manufacturing\r\n    Surface Nanocrystallization - Novel Manufacturing Process Development\r\n    Engineering the Surfaces for Improved Performance\r\n    Fatigue and Fracture Mechanics of Advanced Engineering Materials\r\n    Tribo Characteristics of Biomaterials and Polymer Nano Composites', 'Dr Eng, (Japan)\r\nMS (IIT Madras)\r\nBE (Bharathiyar Un', 'Dr Eng, (Japan)\r\nMS (IIT Madras)\r\nBE (Bharathiyar Un', 'Dr Eng, (Japan)\r\nMS (IIT Madras)\r\nBE (Bharathiyar Un', 'Dr Eng, (Japan)\r\nMS (IIT Madras)\r\nBE (Bharathiyar Un', 'Dr Eng, (Japan)\r\nMS (IIT Madras)\r\nBE (Bharathiyar Un', 1),
(23, '1', '1', '0', '1', '', '', '', '', '', '', '', 1),
(26, '5', '6', '6', '1', 'Ndmmnkdnfjfjf,fn', 'cfvbmf,d,s', 'dcckd,,,,,', 'kdifhhbfhf', 'fnvedmlf nf', 'mdcd..vfm ,vf', 'ff  mfd..dd,', 1),
(27, '50', '2', '5', '5', '', '', '', '', '', '', '', 1),
(29, '', '', '', '', 'd jks k jk kdjk d d nkjdn', 'bfsbfkbkfsjbkjsfb jksf bkjfs bkb k', 'fjbkfbsk ', 'kzv m v91bdd', 'kjkdfbndkdhbsbhjvsv', 'jfnjbnkdjbnkf', 'sgbdgiusdgi', 0),
(35, '', '', '', '', '', '', '', '', '', '', '', 0),
(39, '2', '44', '33', '4', 'skjdfnskj', 'kjsdfnk', 'knkrw', 'srwlkn', 'wrejw', 'jaheihwol', 'khdkan', 1),
(54, '7', '6', '3', '8', '', '', '', '', '', '', '', 1),
(55, '1', '1', '1', '1', '', '', '', '', '', '', '', 1),
(56, '4', '4', '4', '4', '', '', '', '', '', '', '', 1);

-- --------------------------------------------------------

--
-- Table structure for table `form4`
--

CREATE TABLE IF NOT EXISTS `form4` (
  `userid` int(11) NOT NULL,
  `sop25a` varchar(4000) DEFAULT NULL,
  `sop25b` varchar(4000) DEFAULT NULL,
  `ref1_name` varchar(200) DEFAULT NULL,
  `ref2_name` varchar(200) DEFAULT NULL,
  `ref3_name` varchar(200) DEFAULT NULL,
  `otherinfo27` varchar(5000) DEFAULT NULL,
  `submitted` tinyint(1) NOT NULL DEFAULT '0',
  `ref1_addr` varchar(100) DEFAULT NULL,
  `ref2_addr` varchar(100) DEFAULT NULL,
  `ref3_addr` varchar(100) DEFAULT NULL,
  `ref1_email` varchar(50) DEFAULT NULL,
  `ref2_email` varchar(50) DEFAULT NULL,
  `ref3_email` varchar(50) DEFAULT NULL,
  `ref1_phone` varchar(50) DEFAULT NULL,
  `ref2_phone` varchar(50) DEFAULT NULL,
  `ref3_phone` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`userid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `form4`
--

INSERT INTO `form4` (`userid`, `sop25a`, `sop25b`, `ref1_name`, `ref2_name`, `ref3_name`, `otherinfo27`, `submitted`, `ref1_addr`, `ref2_addr`, `ref3_addr`, `ref1_email`, `ref2_email`, `ref3_email`, `ref1_phone`, `ref2_phone`, `ref3_phone`) VALUES
(6, 'hjb ', 'bhjbhj', 'bhb', 'bh', 'b', 'hb', 1, 'hb', 'bb', 'hb', 'hb', 'h', 'hb', 'h', 'bh', 'hb'),
(9, 'dfa', 's', 'a', 'a', 'a', 'aa', 1, 's', 's', 's', 's', 'a', 'w', '1', '2', '3'),
(10, 'Hello Sadagopan\r\n\r\nWelcome! Your registration  with test.site is completed.\r\n\r\nRegards,\r\nWebmaster\r\ntest.site', 'Hello Sadagopan\r\n\r\nWelcome! Your registration  with test.site is completed.\r\n\r\nRegards,\r\nWebmaster\r\ntest.site', 'nsn', 'dr', 'nsn', '', 1, 'iitm', 'nsn', 'iitm', 'swamy@iitm.ac.in', 'swamy@iitm.ac.in', 'swamy@iitm.ac.in', '22574369', '22574369', '22574369'),
(14, 'kjnkjbnbkj', 'jknkjnoklnj', 'njnj', 'jnj', 'njn', 'n', 1, 'njn', 'njn', 'jn', 'njn', 'jnj', 'j', 'njn', 'nj', 'nj'),
(15, 'mklmk', '', 'kjj', '', '', '', 0, '', '', '', '', '', '', '', '', ''),
(16, 'dear students,\r\n\r\nAs you know, our institute lawn tennis court is ready. Kindly go through the attached files for rules and membership details. For any clarification, meet your PTI. \r\n\r\nSubmit your membership application on or before 25/02/2014 to PTI.\r\nregards,\r\nShalu (Faculty in charge, spor', 'dear students,\r\n\r\nAs you know, our institute lawn tennis court is ready. Kindly go through the attached files for rules and membership details. For any clarification, meet your PTI. \r\n\r\nSubmit your membership application on or before 25/02/2014 to PTI.\r\nregards,\r\nShalu (Faculty in charge, spor', 'Anand', 'Ramesh', 'Sowmya', 'dear students,\r\n\r\nAs you know, our institute lawn tennis court is ready. Kindly go through the attached files for rules and membership details. For any clarification, meet your PTI. \r\n\r\nSubmit your membership application on or before 25/02/2014 to PTI.\r\nregards,\r\nShalu (Faculty in charge, spor', 1, 'Germany', 'Canada', 'Maldives', 'coe10b001', 'coe10b013', 'coe10b015', '12334', '4311', '123456'),
(23, 'NHJNJ', 'NJNJNJ', 'HBBH', 'HBHB', 'HBH', 'H', 1, 'HBH', 'HBH', 'BH', 'BH@njn.com', 'B@jmc.com', 'B@sk.com', 'B', 'HB', 'HB'),
(26, 'mc k,,,,,,,,,,,,,,,,c', 'd ckdck f fv', 'mddcmd', 'l,dcl,dll', 'fmv,,,f,f', 'ffmfffmmmfvmmv', 1, 'cmcfccmc,', 'd,,f,,v', ' fm mf m', 'achantamounica@gmail.com', 'achantamounica@gmail.com', 'achantamounica@gmail.com', '919445419520', '919445419520', '919445419520'),
(27, 'uhgvuwebgvubfoqibefvibfi', 'bfqeiobfqiebfi', 'wfb', 'moni', 'mad', 'cbwiuebvojsdcnkbvwkv', 1, 'iwfhb', 'IIIT', 'man', 'coe11b027@iiitdm.ac.in', 'coe11b001@iiitdm.ac.in', 'coe11b027@iiitdm.ac.in', '7299417911', '9441440758', '917299417911'),
(29, 'knkjbnk', 'jnskjnsf', 'ksvn', 'klkvs', 'lksnsnvklnv', 'mskllvksnvln', 0, 'SNKN', 'dlvsnlv', 'kmskvlk', 'mvnlskd', 'lklvdkns', 'kmkldsvnk', 'ikldvsdnn', 'kskvvn', 'kslnvlnvn'),
(35, 'for enjoyment', 'brick by brick should do it\r\nnote:not exceeded 4000 characters', 'babu', 'sandeep', 'robert', '', 0, '202', '207', '116', 'babu@cricket.com', 'gonemad@facebook.com', 'sampoornesh@hero.com', 'nokia lumia 520', 'nokia basic model', 'samsung galaxy'),
(39, 'ljwqekhqk', 'khdkqqke', 'ahei', 'hdhid', 'hdhd', 'jhdbjbdshjb', 1, 'sfwihiu', '93402', '09i0', 'iwheriwh@kjfnks.com', 'hfeidhi@kjks.com', 'jhub@hfsk.com', '7668779', '823420', '230280'),
(54, 'jlk', 'kjhkjh', 'kjlj', 'kjbkj', 'bmknbk', 'khj', 1, 'jhkj', 'bmkh', 'hkjh', 'av@nc.com', 'as@nm.com', 'as@fg.com', '987987', '987987i8', '98787'),
(55, 'ljkljklj', 'kjkljklj', 'kljklj', 'hkjhj', 'hhjkhjkhjk', '', 1, 'lkjlkj', 'jkjkhjk', 'kjhjkhjkh', 'ljklj@khjh.ckhj', 'iiouio@khkh.gjh', 'uyioyuihy@jhkjh.ckjkl', '97897', '98789789', '9897897'),
(56, 'kjhkjh', 'kkhkjhjk', 'kjhjkhkjh', 'kjhukhjkh', 'iiyuiy', '', 1, 'kjhkjhjkh', 'kjhjh', 'yuuiy', 'hkj@hjkhjk.cjh', 'hjkhjkh@jhjk.ckjj', 'fhgffgh@jhjkhjk.cjk', '78678678', '7867786', '67567567');

-- --------------------------------------------------------

--
-- Table structure for table `spons_co_investigator`
--

CREATE TABLE IF NOT EXISTS `spons_co_investigator` (
  `userid` int(11) NOT NULL,
  `sno` int(11) NOT NULL,
  `title` varchar(100) NOT NULL,
  `agency` varchar(100) NOT NULL,
  `value` text NOT NULL,
  `status` varchar(100) NOT NULL,
  PRIMARY KEY (`userid`,`sno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `spons_co_investigator`
--

INSERT INTO `spons_co_investigator` (`userid`, `sno`, `title`, `agency`, `value`, `status`) VALUES
(6, 1, '', '', '', ''),
(7, 1, '', '', '', ''),
(9, 1, '', '', '', ''),
(10, 1, '', '', '', ''),
(14, 1, '', '', '', ''),
(15, 1, '', '', '', ''),
(16, 1, '', '', '', ''),
(16, 2, '', '', '', ''),
(23, 1, '', '', '', ''),
(26, 1, 'kfkmfkfm nvfnnvm', 'nfvfn', '6', 'ddkdmd '),
(27, 1, '', '', '', ''),
(29, 1, '', '', '', ''),
(35, 1, '', '', '', ''),
(39, 1, 'kjfdjsk', 'kjsjkdj', '8888', 'jdnaj'),
(54, 1, '', '', '', ''),
(55, 1, '', '', '', ''),
(56, 1, '', '', '', '');

-- --------------------------------------------------------

--
-- Table structure for table `spons_principal`
--

CREATE TABLE IF NOT EXISTS `spons_principal` (
  `userid` int(11) NOT NULL,
  `sno` int(11) NOT NULL,
  `title` varchar(100) NOT NULL,
  `agency` varchar(100) NOT NULL,
  `value` text NOT NULL,
  `status` varchar(100) NOT NULL,
  PRIMARY KEY (`userid`,`sno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `spons_principal`
--

INSERT INTO `spons_principal` (`userid`, `sno`, `title`, `agency`, `value`, `status`) VALUES
(6, 1, '', '', '', ''),
(7, 1, 'hgghfghf', 'fgfgh', 'gfg', 'gfgf'),
(7, 2, 'fghfgh', 'fhgf', 'hgfgh', 'utuyyt'),
(9, 1, '', '', '', ''),
(10, 1, '', '', '', ''),
(14, 1, '', '', '', ''),
(15, 1, 'undefined', 'undefined', '', 'undefined'),
(16, 1, '', '', '', ''),
(16, 2, '', '', '', ''),
(23, 1, '', '', '', ''),
(26, 1, 'm,,mn', 'mk,mk', '10000', 'jdjnnbv'),
(27, 1, '', '', '', ''),
(27, 2, '', '', '', ''),
(29, 1, '', '', '', ''),
(35, 1, '', '', '', ''),
(39, 1, '', '', '', ''),
(54, 1, 'hgg', 'jgjhg', '5671786', 'dhgj'),
(55, 1, '', '', '', ''),
(56, 1, '', '', '', '');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `id_user` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(128) NOT NULL,
  `email` varchar(64) NOT NULL,
  `phone_number` varchar(16) NOT NULL,
  `username` varchar(16) NOT NULL,
  `password` varchar(32) NOT NULL,
  `confirmcode` varchar(32) DEFAULT NULL,
  `submitted` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id_user`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=57 ;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id_user`, `name`, `email`, `phone_number`, `username`, `password`, `confirmcode`, `submitted`) VALUES
(6, 'pandi', 'coe10b010@iiitdm.ac.in', '', 'pandi', 'e351836df9fa734a2c7d589f521fa6f4', 'y', 1),
(7, 'Deepthi', 'deepthireddy2309@gmail.com', '', 'Deepthi', 'fd1fe2683f46f5bb525a9d8a70ea9419', 'y', 0),
(9, 'Sadagopan', 'sadagopan@iiitdm.ac.in', '', 'Sadagopan', '4f60cf2e7181ba18b0429b93ae48db5a', 'y', 1),
(10, 'sada', 'sadagopan.narasimhan@gmail.com', '', 'sada', '7eee9eccbdde6fd6f3b85c135d62133a', 'y', 1),
(14, 'Anand', 'anandvij.del@gmail.com', '', 'anand', '8bda8e915e629a9fd1bbca44f8099c81', 'y', 1),
(15, 'Sowmya Jain', 'sowmyajain@yahoo.co.in', '', 'sowmya', 'f79a3eb241e5c2cf8f757d8322788dd5', 'y', 0),
(16, 'Deepthi Reddy', 'coe10b008@iiitdm.ac.in', '', 'Deeps', 'e00b7a4a9a30ea9ed612b7f1408341b6', 'y', 1),
(17, 'admin', 'coe10b015@iiitdm.ac.in', '', 'admin', 'c44395ff748d366e653e11cde996e2ed', 'y', 0),
(23, 'sonu', 'sowmyajain1992@gmail.com', '', 'sonu', '371ab955fdc11c44c980779c3135b155', 'y', 1),
(24, 'Madhu', 'coe11b012@iiitdm.ac.in', '', 'Madhu', '84811fed582a9c7b8cb41f68f0ed6147', 'y', 0),
(25, 'vijay', 'coe11b002@iiitdm.ac.in', '', 'vijay', '4f9fecabbd77fba02d2497f880f44e6f', 'y', 0),
(26, 'Monika Achanta', 'coe11b001@iiitdm.ac.in', '', 'Monika', '6f3fc039bfe1efdb272111f276a0e84a', 'y', 1),
(27, 'mano', 'coe11b027@iiitdm.ac.in', '', 'mano', '1ad8ffaf4f70a0bc515181e8295f64c7', 'y', 1),
(28, 'sowmya noone', 'sowmya0309@gmail.com', '', 'noone', '71bfcaedba59577ecbdcb68085e58a01', 'y', 0),
(29, 'kri', 'coe11b014@iiitdm.ac.in', '', 'krishna127', '9c02e3946b955dd584e2269e8ae88c62', 'y', 0),
(30, 'robertkiran', 'robertkiran.d@gmail.com', '', 'robertkiran.d', 'f1817ae498ec5c58c5bcc1de10217cfe', 'y', 0),
(32, 'Kuladeep', 'coe11b026@iiitdm.ac.in', '', 'kuladeep', '8ca1c1ec099e297cb814a224b26349f3', 'y', 0),
(33, 'oswald c', 'oswald.mecse@gmail.com', '', 'oswald', '836987ffe64efbd7ca03e74908726456', 'y', 0),
(34, 'sadklnfdsknfdsk', 'coe11b004@iiitdm.ac.in', '', 'sandeep', '172aa9ae63499bbe40c6505ef03a197b', 'y', 0),
(35, 'dellhp', 'coe11b011@iiitdm.ac.in', '', 'hpdell', '314315dcb5b41d8ae7cd27057b3bd612', 'y', 0),
(36, 'krishna', 'krishna.iiitdm@gmail.com', '', 'krishna', '243bd1ce0387f18005abfc43b001646a', 'e6c9d66f938451f15d9691fbc4ae0884', 0),
(37, 'sai', 'coe11b005@iiitdm.ac.in', '', 'bmw', '79cfac6387e0d582f83a29a04d0bcdc4', 'y', 0),
(39, 'Madhu', 'imadhulahari@gmail.com', '', 'Madhu123', '63faf9a9e04759f4ece532f53c0c8129', 'y', 1),
(40, 'Krishna Chaurasia', 'coe11b016@iiitdm.ac.in', '', 'coe11b016', '243bd1ce0387f18005abfc43b001646a', 'y', 0),
(41, '123', 'coe11b024@iiitdm.ac.in', '', 'dasas', '2f3e9eccc22ee583cf7bad86c751d865', 'y', 0),
(42, 'sadklnfdskn', 'avulasandeep999@gmail.com', '', 'sanasdf', '6eea9b7ef19179a06954edd0f6c05ceb', '72018ed242a8b69794e92e424259b6f9', 0),
(43, 'Ashish', 'coe11b003@iiitdm.com', '', 'ashu', '1a1dc91c907325c69271ddf0c944bc72', '8c89aa1bf0ab3a16cba8ca1cba125a15', 0),
(45, 'RAM NAIK', 'coe11b017@iiitdm.ac.in', '', 'RAM', '0ea75c44d4335a1bf5c4f411c589564f', 'y', 0),
(46, 'sai', 'coe11b018@iiitdm.ac.in', '', 'saik', '2f3e9eccc22ee583cf7bad86c751d865', '45f382aaa898128de2ac6b98339cc4e4', 0),
(48, 'vijaykumarm', 'vijayiiitdm@gmail.com', '', 'vijaykumarm', '4f9fecabbd77fba02d2497f880f44e6f', 'e16a4a5c617925b39e8501fe744ecc5a', 0),
(50, 'Ashish kamble', 'coe11b003@iiitdm.ac.in', '', 'ashish', '1a1dc91c907325c69271ddf0c944bc72', 'y', 0),
(51, 'Sid', 'pulsid.agarwal@gmail.com', '', 'myself', 'cc03e747a6afbbcbf8be7668acfebee5', 'd208e7ab21db0d0fc0c351e024880bb4', 0),
(52, 'manogna', 'manogna1409@gmail.com', '', 'manogna', '5b4d762427d4dff75f6e5885cb380080', '1ce888f966b19a8baffdec635db09b86', 0),
(53, 'Suni lkumar', 'coe11b009@iiitdm.ac.in', '', 'sunilkumar', '094cc89ac4011640ea8a980fccfaecf9', 'y', 0),
(54, 'Anand', 'coe10b001@iiitdm.ac.in', '', 'anand1', 'f59d4549ea4fe7ba6904e5ee1e7d9754', 'y', 1),
(55, 'Ramesh', 'coe10b013@iiitdm.ac.in', '', 'ramesh', '6fc42c4388ed6f0c5a91257f096fef3c', 'y', 1),
(56, 'Ramesh', 'psrk92@gmail.com', '', 'ramesh1', 'f56222ad376450b3b1178842381978ce', 'y', 1);

-- --------------------------------------------------------

--
-- Stand-in structure for view `view1`
--
CREATE TABLE IF NOT EXISTS `view1` (
`userid` int(11)
);
-- --------------------------------------------------------

--
-- Table structure for table `work_experience`
--

CREATE TABLE IF NOT EXISTS `work_experience` (
  `userid` int(11) NOT NULL,
  `sno` int(11) NOT NULL,
  `name` varchar(100) NOT NULL,
  `designation` varchar(100) NOT NULL,
  `doj` date NOT NULL,
  `dol` date NOT NULL,
  `duration` text NOT NULL,
  `scale` text NOT NULL,
  PRIMARY KEY (`userid`,`sno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `work_experience`
--

INSERT INTO `work_experience` (`userid`, `sno`, `name`, `designation`, `doj`, `dol`, `duration`, `scale`) VALUES
(6, 1, ' n', '  ', '0000-00-00', '0000-00-00', 'n ', 'n '),
(6, 2, '', '', '0000-00-00', '0000-00-00', '', ''),
(7, 1, 'Asdd', 'hghjg', '0000-00-00', '0000-00-00', '78-09', 'h675'),
(9, 1, '', '', '0000-00-00', '0000-00-00', '', ''),
(10, 1, 'iisc', 'postdoc', '2012-05-01', '2012-08-01', '0-3', 'none'),
(10, 2, 'n/a', 'n/a', '0000-00-00', '0000-00-00', '', ''),
(14, 1, '', '', '0000-00-00', '0000-00-00', '', ''),
(15, 1, 'l', 'k', '0000-00-00', '0000-00-00', '3', '4'),
(16, 1, 'Georgia Tech', 'HOD, CS&ECE', '2021-08-01', '2031-08-01', '10-00', '1000000000'),
(23, 1, 'nnjn', 'njnj', '0000-00-00', '0000-00-00', 'jnj', 'njn'),
(26, 1, 'c,,,f,', 'v vmmfnkvfk', '2013-11-29', '0123-02-22', 'kvk', '2000000000'),
(27, 1, '', '', '2022-09-07', '2050-08-09', '20', '100000'),
(29, 1, 'gfdgd', 'hgfhgf', '0055-05-04', '0003-05-04', '7777', '7979977'),
(35, 1, '', '', '0000-00-00', '0000-00-00', '', ''),
(39, 1, 'jadkq', 'khsbkw', '4444-02-03', '2222-02-04', '34', '8282828'),
(54, 1, 'hbj', 'hkjhb', '1991-02-23', '1993-04-16', '09-09', '1000000000'),
(54, 2, 'khkj', 'khk', '1991-02-23', '1991-02-23', '08-08', '10038'),
(55, 1, '', '', '0000-00-00', '0000-00-00', '', ''),
(56, 1, '', '', '0000-00-00', '0000-00-00', '', '');

-- --------------------------------------------------------

--
-- Structure for view `view1`
--
DROP TABLE IF EXISTS `view1`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `view1` AS select distinct `F1`.`userid` AS `userid` from (`form1` `F1` join `form2` `F2`) where ((`F1`.`userid` = `F2`.`userid`) and (`F1`.`adno` = '1234') and (`F1`.`category` = 'ST'));

--
-- Constraints for dumped tables
--

--
-- Constraints for table `form1`
--
ALTER TABLE `form1`
  ADD CONSTRAINT `form1_ibfk_1` FOREIGN KEY (`userid`) REFERENCES `users` (`id_user`);

--
-- Constraints for table `form2`
--
ALTER TABLE `form2`
  ADD CONSTRAINT `form2_ibfk_2` FOREIGN KEY (`userid`) REFERENCES `users` (`id_user`);

--
-- Constraints for table `form3`
--
ALTER TABLE `form3`
  ADD CONSTRAINT `form3_ibfk_2` FOREIGN KEY (`userid`) REFERENCES `users` (`id_user`);

--
-- Constraints for table `form4`
--
ALTER TABLE `form4`
  ADD CONSTRAINT `form4_ibfk_1` FOREIGN KEY (`userid`) REFERENCES `users` (`id_user`);

--
-- Constraints for table `spons_co_investigator`
--
ALTER TABLE `spons_co_investigator`
  ADD CONSTRAINT `spons_co_investigator_ibfk_1` FOREIGN KEY (`userid`) REFERENCES `users` (`id_user`);

--
-- Constraints for table `spons_principal`
--
ALTER TABLE `spons_principal`
  ADD CONSTRAINT `spons_principal_ibfk_1` FOREIGN KEY (`userid`) REFERENCES `users` (`id_user`);

--
-- Constraints for table `work_experience`
--
ALTER TABLE `work_experience`
  ADD CONSTRAINT `work_experience_ibfk_1` FOREIGN KEY (`userid`) REFERENCES `users` (`id_user`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
