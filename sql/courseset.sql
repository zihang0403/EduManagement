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

 Date: 17/12/2023 22:43:20
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

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
  CONSTRAINT `studentid` FOREIGN KEY (`studentid`) REFERENCES `studentinfo` (`studentid`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `courseid` FOREIGN KEY (`courseid`) REFERENCES `courseinfo` (`courseid`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `teacherid` FOREIGN KEY (`teacherid`) REFERENCES `teacherinfo` (`teacherid`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of courseset
-- ----------------------------
INSERT INTO `courseset` VALUES ('10001', '1', '10001', '', NULL, NULL, NULL);

SET FOREIGN_KEY_CHECKS = 1;
