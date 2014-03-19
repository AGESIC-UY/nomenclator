--        ____                                      
--       / __/________  ___        ____ _____ _   __
--      / /_ / ___/ _ \/ _ \______/ __ `/ __ \ | / /
--     / __// /  /  __/  __/_____/ /_/ / /_/ / |/ / 
--    /_/  /_/   \___/\___/      \__, /\____/|___/   > http://free-gov.org
--                              /____/              
-- 
-- This file is part of 'Free-gov' - nomenclator.sql
--     
-- Free-gov - e-government free software system
-- Copyright (C) 2011 Iris Montes de Oca <http://www.irismontesdeoca.com>
-- Copyright (C) 2011 Eduardo Glez <http://www.eduardoglez.com>
-- 
-- Free-gov is free software; you can redistribute it and/or modify
-- it under the terms of the GNU Affero General Public License as published 
-- by the Free Software Foundation; either version 3 of the License, or
-- (at your option) any later version.
-- 
-- Free-gov is distributed in the hope that it will be useful, 
-- but WITHOUT ANY WARRANTY; without even the implied warranty of 
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
-- GNU Affero General Public License for more details.
-- 
-- You should have received a copy of the GNU Affero General Public License
-- along with Free-gov: see the file 'license.txt'.  If not, write to
-- the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
-- Boston, MA 02111-1307, USA.
-- 
--  Authors: Iris Montes de Oca <http://www.irismontesdeoca.com>
--           Eduardo Glez <http://www.eduardoglez.com>
-- Internet: http://free-gov.org
-- 
-- Registered in the United States Copyright Office on May 18, 2011
-- Registration Number at the Library of the Congress of the USA: TXu001756584
-- 


-- Generation Time: Oct 04, 2012 at 09:28 PM
-- Server version: 5.1.53
-- PHP Version: 5.2.17

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

-- --------------------------------------------------------

--
-- Table structure for table `acl_groups`
--

CREATE TABLE IF NOT EXISTS `acl_groups` (
  `name` varchar(20) NOT NULL,
  `description` varchar(100) DEFAULT NULL,
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `acl_groups`
--

INSERT INTO `acl_groups` (`name`, `description`) VALUES
('admin', 'can do everything'),
('nomenclator_admin', 'manage nomenclator');

-- --------------------------------------------------------

--
-- Table structure for table `acl_groups2res`
--

CREATE TABLE IF NOT EXISTS `acl_groups2res` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `group` varchar(20) NOT NULL,
  `module` varchar(60) NOT NULL COMMENT 'resource is: module/operation',
  `operation` varchar(30) NOT NULL COMMENT 'resource is: module/operation',
  `negative` tinyint(1) NOT NULL DEFAULT '0',
  `menu_group` varchar(65) DEFAULT NULL,
  `menu_caption` varchar(65) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=14 ;

--
-- Dumping data for table `acl_groups2res`
--

INSERT INTO `acl_groups2res` (`id`, `group`, `module`, `operation`, `negative`, `menu_group`, `menu_caption`) VALUES
(1, 'nomenclator_admin', 'nomenclator', 'idiomas', 0, 'Configuraciones', 'Idiomas'),
(2, 'nomenclator_admin', 'nomenclator', 'idiomas_c', 0, NULL, NULL),
(3, 'nomenclator_admin', 'nomenclator', 'idiomas_d', 0, NULL, NULL),
(4, 'nomenclator_admin', 'nomenclator', 'categorias', 0, 'Configuraciones', 'Categorí­as'),
(5, 'nomenclator_admin', 'nomenclator', 'categorias_c', 0, NULL, NULL),
(6, 'nomenclator_admin', 'nomenclator', 'categorias_d', 0, NULL, NULL),
(7, 'nomenclator_admin', 'nomenclator', 'barrios', 0, 'Configuraciones', 'Barrios'),
(8, 'nomenclator_admin', 'nomenclator', 'barrios_c', 0, NULL, NULL),
(9, 'nomenclator_admin', 'nomenclator', 'barrios_d', 0, NULL, NULL),
(10, 'nomenclator_admin', 'nomenclator', 'calles', 0, 'Elementos del nomenclator', 'Listar / buscar'),
(11, 'nomenclator_admin', 'nomenclator', 'calles_c', 0, NULL, NULL),
(12, 'nomenclator_admin', 'nomenclator', 'calles_d', 0, NULL, NULL),
(13, 'nomenclator_admin', 'nomenclator', 'calles_f', 0, NULL, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `acl_metagroups`
--

CREATE TABLE IF NOT EXISTS `acl_metagroups` (
  `name` varchar(20) NOT NULL,
  `description` varchar(100) DEFAULT NULL,
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `acl_metagroups`
--


-- --------------------------------------------------------

--
-- Table structure for table `acl_metagroups2groups`
--

CREATE TABLE IF NOT EXISTS `acl_metagroups2groups` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `metagroup` varchar(20) NOT NULL,
  `group` varchar(20) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

--
-- Dumping data for table `acl_metagroups2groups`
--


-- --------------------------------------------------------

--
-- Table structure for table `acl_users`
--

CREATE TABLE IF NOT EXISTS `acl_users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(20) NOT NULL,
  `cryptpass` varchar(40) NOT NULL,
  `realname` varchar(40) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=2 ;

--
-- Dumping data for table `acl_users`
--
-- User: 'usuarioinicial' Password: 'cambiarurgente'

INSERT INTO `acl_users` (`id`, `username`, `cryptpass`, `realname`) VALUES
(1, 'usuarioinicial', '7e2a36a3697c83544ce49c35bb5c7bfe8ec50fc6', 'Usuario Inicial');

-- --------------------------------------------------------

--
-- Table structure for table `acl_users2groups`
--

CREATE TABLE IF NOT EXISTS `acl_users2groups` (
  `user` int(11) NOT NULL,
  `group` varchar(20) NOT NULL,
  KEY `user` (`user`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `acl_users2groups`
--

INSERT INTO `acl_users2groups` (`user`, `group`) VALUES
(1, 'nomenclator_admin');

-- --------------------------------------------------------

--
-- Table structure for table `acl_users2metagroups`
--

CREATE TABLE IF NOT EXISTS `acl_users2metagroups` (
  `user` int(11) NOT NULL,
  `metagroup` varchar(20) NOT NULL,
  KEY `user` (`user`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `acl_users2metagroups`
--


-- --------------------------------------------------------

--
-- Table structure for table `log`
--

CREATE TABLE IF NOT EXISTS `log` (
  `datetime` datetime NOT NULL,
  `ip` varchar(46) NOT NULL,
  `xforwardedf` varchar(46) DEFAULT NULL,
  `useragent` text NOT NULL,
  `userid` int(11) NOT NULL,
  `event` varchar(15) NOT NULL,
  `details` text,
  PRIMARY KEY (`datetime`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `log`
--

-- --------------------------------------------------------

--
-- Table structure for table `nomenclator_barrios`
--

CREATE TABLE IF NOT EXISTS `nomenclator_barrios` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(70) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=10 ;

--
-- Dumping data for table `nomenclator_barrios`
--

INSERT INTO `nomenclator_barrios` (`id`, `name`) VALUES
(1, 'Centro'),
(2, 'San Francisco'),
(3, 'Villa Delia'),
(4, 'Apiario'),
(5, 'Tassano'),
(6, 'Mussio'),
(7, 'Norte'),
(8, 'Lavalleja'),
(9, 'Artigas');

-- --------------------------------------------------------

--
-- Table structure for table `nomenclator_calles`
--

CREATE TABLE IF NOT EXISTS `nomenclator_calles` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(150) NOT NULL,
  `text` text NOT NULL,
  `barrio` int(11) NOT NULL,
  `categoria` int(11) NOT NULL,
  `idioma` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

--
-- Dumping data for table `nomenclator_calles`
--

-- --------------------------------------------------------

--
-- Table structure for table `nomenclator_categorias`
--

CREATE TABLE IF NOT EXISTS `nomenclator_categorias` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(40) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=12 ;

--
-- Dumping data for table `nomenclator_categorias`
--

INSERT INTO `nomenclator_categorias` (`id`, `name`) VALUES
(1, 'Calle'),
(2, 'Avenida'),
(3, 'Plaza'),
(4, 'Parque'),
(5, 'Monumento'),
(6, 'Edificio'),
(7, 'Museo'),
(8, 'Estadio'),
(9, 'Puente'),
(10, 'Camino'),
(11, 'Ruta');

-- --------------------------------------------------------

--
-- Table structure for table `nomenclator_idiomas`
--

CREATE TABLE IF NOT EXISTS `nomenclator_idiomas` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(40) NOT NULL,
  `suffix` varchar(2) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `nomenclator_idiomas`
--

INSERT INTO `nomenclator_idiomas` (`id`, `name`, `suffix`) VALUES
(1, 'Español', 'es'),
(2, 'Portugués Brasil', 'br'),
(3, 'Inglés', 'en');

-- --------------------------------------------------------


