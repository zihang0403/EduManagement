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

 Date: 21/12/2023 13:35:59
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for majorinfo
-- ----------------------------
DROP TABLE IF EXISTS `majorinfo`;
CREATE TABLE `majorinfo`  (
  `id` char(16) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `major` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `instituteid` char(16) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `institute` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `instituteid`(`instituteid`) USING BTREE,
  INDEX `institute`(`institute`) USING BTREE,
  CONSTRAINT `instituteid` FOREIGN KEY (`instituteid`) REFERENCES `instituteinfo` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `institute` FOREIGN KEY (`institute`) REFERENCES `instituteinfo` (`institute`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of majorinfo
-- ----------------------------
INSERT INTO `majorinfo` VALUES ('01', '无机非金属材料工程', '01', '材料科学与工程学院');

SET FOREIGN_KEY_CHECKS = 1;
