/*
 Navicat Premium Data Transfer

 Source Server         : Zihang
 Source Server Type    : MySQL
 Source Server Version : 80023
 Source Host           : localhost:3306
 Source Schema         : edumanagement

 Target Server Type    : MySQL
 Target Server Version : 80023
 File Encoding         : 65001

 Date: 14/12/2023 13:32:40
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
  `bornday` date NOT NULL,
  PRIMARY KEY (`studentid`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of studentinfo
-- ----------------------------
INSERT INTO `studentinfo` VALUES ('19010101', '123456', 'a', '1', '2012-01-23');
INSERT INTO `studentinfo` VALUES ('19010102', '123456', 'b', '1', '2012-01-23');
INSERT INTO `studentinfo` VALUES ('19010103', '123456', 'c', '1', '2012-01-23');
INSERT INTO `studentinfo` VALUES ('4', '1', 'd', '1', '2012-01-23');

SET FOREIGN_KEY_CHECKS = 1;
