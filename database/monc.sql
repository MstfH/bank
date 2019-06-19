CREATE DATABASE IF NOT EXISTS `monc`;
USE `monc`;

CREATE TABLE IF NOT EXISTS `accounts` (
  `ID` int(11) NOT NULL,
  `Rekeningnummer` varchar(10) NOT NULL,
  `Saldo` int(11) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `Rekeningnummer` (`Rekeningnummer`),
  CONSTRAINT `accounts_ibfk_1` FOREIGN KEY (`Rekeningnummer`) REFERENCES `debitcard` (`Rekeningnummer`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS `debitcard` (
  `Rekeningnummer` varchar(10) NOT NULL,
  `Pincode` int(4) NOT NULL,
  `Pasnummer` varchar(11) NOT NULL,
  `Kansen` int(2) NOT NULL,
  PRIMARY KEY (`Rekeningnummer`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS `klanten` (
  `ID` int(11) NOT NULL,
  `Achternaam` varchar(50) NOT NULL,
  `Voornaam` varchar(50) NOT NULL,
  `Geboortedatum` date NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS `transacties` (
  `TransactieID` int(11) NOT NULL,
  `Rekeningnummer` varchar(10) NOT NULL,
  `HoeveelGeld` float NOT NULL,
  `Beschrijving` varchar(100) DEFAULT NULL,
  `Datum` date NOT NULL,
  PRIMARY KEY (`TransactieID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS `werknemers` (
  `ID` int(11) NOT NULL,
  `Achternaam` varchar(50) NOT NULL,
  `Voornaam` varchar(50) NOT NULL,
  `Geboortedatum` date NOT NULL,
  `Functie` varchar(20) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

