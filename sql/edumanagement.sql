/*
 Navicat Premium Data Transfer

 Source Server         : zihang
 Source Server Type    : MySQL
 Source Server Version : 80023
 Source Host           : localhost:3306
 Source Schema         : edumanagement

 Target Server Type    : MySQL
 Target Server Version : 80023
 File Encoding         : 65001

 Date: 20/12/2023 22:54:27
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for courseinfo
-- ----------------------------
DROP TABLE IF EXISTS `courseinfo`;
CREATE TABLE `courseinfo`  (
  `courseid` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `coursescore` float NULL DEFAULT NULL,
  `courseperiod` int(0) NULL DEFAULT NULL,
  `institute` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`courseid`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of courseinfo
-- ----------------------------
INSERT INTO `courseinfo` VALUES ('1', '1', 1, 1, '计算机与信息工程学院');
INSERT INTO `courseinfo` VALUES ('10001', '高等数学', 4.5, 64, '计算机与信息工程学院');
INSERT INTO `courseinfo` VALUES ('10002', '数据结构', 4.5, 64, '计算机与信息工程学院');
INSERT INTO `courseinfo` VALUES ('10003', '计算机网络', 3, 48, '计算机与信息工程学院');
INSERT INTO `courseinfo` VALUES ('10004', '线性代数', 4, 48, '计算机与信息工程学院');
INSERT INTO `courseinfo` VALUES ('10005', '大学物理', 3, 48, '计算机与信息工程学院');
INSERT INTO `courseinfo` VALUES ('10006', '大学物理', 3, 48, '计算机与信息工程学院');

-- ----------------------------
-- Table structure for courseset
-- ----------------------------
DROP TABLE IF EXISTS `courseset`;
CREATE TABLE `courseset`  (
  `courseid` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `studentid` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `teacherid` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `courseweekday` set('Monday','Tuesday','Wednesday','Thursday','Friday','Saturday','Sunday') CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '',
  `starttime` time(0) NULL DEFAULT NULL,
  `endtime` time(0) NULL DEFAULT NULL,
  `classroom` char(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  INDEX `studentid`(`studentid`) USING BTREE,
  INDEX `courseid`(`courseid`) USING BTREE,
  INDEX `teacherid`(`teacherid`) USING BTREE,
  CONSTRAINT `courseid` FOREIGN KEY (`courseid`) REFERENCES `courseinfo` (`courseid`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `studentid` FOREIGN KEY (`studentid`) REFERENCES `studentinfo` (`studentid`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `teacherid` FOREIGN KEY (`teacherid`) REFERENCES `teacherinfo` (`teacherid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of courseset
-- ----------------------------

-- ----------------------------
-- Table structure for studentinfo
-- ----------------------------
DROP TABLE IF EXISTS `studentinfo`;
CREATE TABLE `studentinfo`  (
  `studentid` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `password` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `name` char(10) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `sex` char(10) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `bornday` date NULL DEFAULT NULL,
  `institute` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`studentid`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of studentinfo
-- ----------------------------
INSERT INTO `studentinfo` VALUES ('19010101', '123456', 'a', '1', '2012-01-23', '计算机与信息工程学院');
INSERT INTO `studentinfo` VALUES ('19010102', '123454', 'b', '1', '2012-01-23', '计算机与信息工程学院');

-- ----------------------------
-- Table structure for teacherinfo
-- ----------------------------
DROP TABLE IF EXISTS `teacherinfo`;
CREATE TABLE `teacherinfo`  (
  `teacherid` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `password` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `name` char(10) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `sex` char(10) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `position` char(10) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `institute` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `bornday` date NULL DEFAULT NULL,
  PRIMARY KEY (`teacherid`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of teacherinfo
-- ----------------------------
INSERT INTO `teacherinfo` VALUES ('10001', '123456', ' 王强', '男', '副教授', '计算机与信息工程学院', '2023-02-21');

SET FOREIGN_KEY_CHECKS = 1;
