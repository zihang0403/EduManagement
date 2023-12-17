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

 Date: 17/12/2023 22:43:26
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

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
INSERT INTO `studentinfo` VALUES ('1', '1', 'd', '1', '2012-01-23', '计算机与信息工程学院');
INSERT INTO `studentinfo` VALUES ('19010101', '123456', 'a', '1', '2012-01-23', '计算机与信息工程学院');
INSERT INTO `studentinfo` VALUES ('19010102', '123454', 'b', '1', '2012-01-23', '计算机与信息工程学院');
INSERT INTO `studentinfo` VALUES ('19010103', '123453', 'c', '1', '2012-01-23', '计算机与信息工程学院');

SET FOREIGN_KEY_CHECKS = 1;
