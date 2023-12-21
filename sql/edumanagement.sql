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

 Date: 21/12/2023 16:30:01
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
  `courseperiod` int NULL DEFAULT NULL,
  `majorid` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `instituteid` char(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `institute` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`courseid`) USING BTREE,
  INDEX `majorid`(`majorid`) USING BTREE,
  INDEX `instituteid2`(`instituteid`) USING BTREE,
  CONSTRAINT `majorid` FOREIGN KEY (`majorid`) REFERENCES `majorinfo` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `instituteid2` FOREIGN KEY (`instituteid`) REFERENCES `instituteinfo` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of courseinfo
-- ----------------------------
INSERT INTO `courseinfo` VALUES ('10001', '高等数学', 5, 64, '01', '04', '计算机与信息工程学院');
INSERT INTO `courseinfo` VALUES ('10002', '数据结构', 4.5, 64, '01', '04', '计算机与信息工程学院');
INSERT INTO `courseinfo` VALUES ('10003', '计算机网络', 3, 48, '01', '04', '计算机与信息工程学院');
INSERT INTO `courseinfo` VALUES ('10004', '线性代数', 4, 48, '01', '04', '计算机与信息工程学院');
INSERT INTO `courseinfo` VALUES ('10005', '大学物理', 3, 48, '01', '04', '计算机与信息工程学院');
INSERT INTO `courseinfo` VALUES ('10006', '概率论与数理统计', 3.5, 64, '01', '04', '计算机与信息工程学院');

-- ----------------------------
-- Table structure for courseset
-- ----------------------------
DROP TABLE IF EXISTS `courseset`;
CREATE TABLE `courseset`  (
  `courseid` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `studentid` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `teacherid` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `courseweekday` set('Monday','Tuesday','Wednesday','Thursday','Friday','Saturday','Sunday') CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '',
  `starttime` time NULL DEFAULT NULL,
  `endtime` time NULL DEFAULT NULL,
  `classroom` char(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  INDEX `studentid`(`studentid`) USING BTREE,
  INDEX `courseid`(`courseid`) USING BTREE,
  INDEX `teacherid`(`teacherid`) USING BTREE,
  CONSTRAINT `courseid` FOREIGN KEY (`courseid`) REFERENCES `courseinfo` (`courseid`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `studentid` FOREIGN KEY (`studentid`) REFERENCES `studentinfo` (`studentid`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `teacherid` FOREIGN KEY (`teacherid`) REFERENCES `teacherinfo` (`teacherid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of courseset
-- ----------------------------
INSERT INTO `courseset` VALUES ('10001', '19010101', '10001', 'Monday', '10:00:00', '12:00:00', 'A103');

-- ----------------------------
-- Table structure for instituteinfo
-- ----------------------------
DROP TABLE IF EXISTS `instituteinfo`;
CREATE TABLE `instituteinfo`  (
  `id` char(16) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `institute` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `institute`(`institute`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of instituteinfo
-- ----------------------------
INSERT INTO `instituteinfo` VALUES ('12', '人文与社会科学学院');
INSERT INTO `instituteinfo` VALUES ('09', '会计学院');
INSERT INTO `instituteinfo` VALUES ('06', '土木工程学院');
INSERT INTO `instituteinfo` VALUES ('11', '外国语学院');
INSERT INTO `instituteinfo` VALUES ('13', '教育科学与音乐学院');
INSERT INTO `instituteinfo` VALUES ('02', '智能制造学院');
INSERT INTO `instituteinfo` VALUES ('01', '材料科学与工程学院');
INSERT INTO `instituteinfo` VALUES ('07', '环境工程与化学学院');
INSERT INTO `instituteinfo` VALUES ('03', '电气工程与自动化学院');
INSERT INTO `instituteinfo` VALUES ('08', '经济与管理学院');
INSERT INTO `instituteinfo` VALUES ('10', '艺术设计学院');
INSERT INTO `instituteinfo` VALUES ('04', '计算机与信息工程学院');
INSERT INTO `instituteinfo` VALUES ('05', '软件学院');

-- ----------------------------
-- Table structure for majorinfo
-- ----------------------------
DROP TABLE IF EXISTS `majorinfo`;
CREATE TABLE `majorinfo`  (
  `index` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `id` char(16) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `major` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `instituteid` char(16) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `institute` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`index`) USING BTREE,
  INDEX `instituteid`(`instituteid`) USING BTREE,
  INDEX `institute`(`institute`) USING BTREE,
  INDEX `id`(`id`) USING BTREE,
  CONSTRAINT `instituteid` FOREIGN KEY (`instituteid`) REFERENCES `instituteinfo` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `institute` FOREIGN KEY (`institute`) REFERENCES `instituteinfo` (`institute`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of majorinfo
-- ----------------------------
INSERT INTO `majorinfo` VALUES (1, '01', '无机非金属材料工程', '01', '材料科学与工程学院');
INSERT INTO `majorinfo` VALUES (2, '02', '材料成型及控制工程', '01', '材料科学与工程学院');
INSERT INTO `majorinfo` VALUES (3, '03', '高分子材料与工程', '01', '材料科学与工程学院');
INSERT INTO `majorinfo` VALUES (4, '04', '材料物理', '01', '材料科学与工程学院');
INSERT INTO `majorinfo` VALUES (5, '05', '焊接技术与工程', '01', '材料科学与工程学院');
INSERT INTO `majorinfo` VALUES (6, '06', '金属材料工程', '01', '材料科学与工程学院');
INSERT INTO `majorinfo` VALUES (7, '01', '机械设计制造及其自动化', '02', '智能制造学院');
INSERT INTO `majorinfo` VALUES (8, '02', '智能制造工程', '02', '智能制造学院');
INSERT INTO `majorinfo` VALUES (9, '03', '机器人工程', '02', '智能制造学院');
INSERT INTO `majorinfo` VALUES (10, '04', '机械电子工程', '02', '智能制造学院');
INSERT INTO `majorinfo` VALUES (11, '05', '车辆工程', '02', '智能制造学院');
INSERT INTO `majorinfo` VALUES (12, '06', '汽车服务工程', '02', '智能制造学院');
INSERT INTO `majorinfo` VALUES (13, '07', '机械设计制造及其自动化', '02', '智能制造学院');
INSERT INTO `majorinfo` VALUES (15, '01', '电气工程及其自动化', '03', '电气工程与自动化学院');
INSERT INTO `majorinfo` VALUES (16, '02', '自动化', '03', '电气工程与自动化学院');
INSERT INTO `majorinfo` VALUES (17, '03', '电子科学技术', '03', '电气工程与自动化学院');
INSERT INTO `majorinfo` VALUES (18, '04', '智能科学技术', '03', '电气工程与自动化学院');
INSERT INTO `majorinfo` VALUES (19, '05', '电气自动化技术', '03', '电气工程与自动化学院');
INSERT INTO `majorinfo` VALUES (20, '01', '计算机科学与技术', '04', '计算机与信息工程学院');
INSERT INTO `majorinfo` VALUES (21, '02', '通信工程', '04', '计算机与信息工程学院');
INSERT INTO `majorinfo` VALUES (22, '03', '软件工程', '04', '计算机与信息工程学院');
INSERT INTO `majorinfo` VALUES (23, '04', '物联网工程', '04', '计算机与信息工程学院');
INSERT INTO `majorinfo` VALUES (24, '05', '数据科学与大数据技术', '04', '计算机与信息工程学院');
INSERT INTO `majorinfo` VALUES (25, '06', '大数据技术', '05', '软件学院');
INSERT INTO `majorinfo` VALUES (26, '01', '土木工程', '06', '土木工程学院');
INSERT INTO `majorinfo` VALUES (27, '02', '建筑环境与能源应用工程', '06', '土木工程学院');
INSERT INTO `majorinfo` VALUES (28, '03', '给排水科学与工程', '06', '土木工程学院');
INSERT INTO `majorinfo` VALUES (29, '04', '工程管理', '06', '土木工程学院');
INSERT INTO `majorinfo` VALUES (30, '05', '工程造价', '06', '土木工程学院');
INSERT INTO `majorinfo` VALUES (31, '06', '土木工程（中爱合作办学）', '06', '土木工程学院');
INSERT INTO `majorinfo` VALUES (32, '01', '环境工程', '07', '环境工程与化学学院');
INSERT INTO `majorinfo` VALUES (33, '02', '资源循环科学与工程', '07', '环境工程与化学学院');
INSERT INTO `majorinfo` VALUES (34, '03', '应用化学', '07', '环境工程与化学学院');
INSERT INTO `majorinfo` VALUES (35, '04', '生物技术', '07', '环境工程与化学学院');
INSERT INTO `majorinfo` VALUES (36, '05', '新能源科学与工程', '07', '环境工程与化学学院');
INSERT INTO `majorinfo` VALUES (37, '01', '工商管理', '08', '经济与管理学院');
INSERT INTO `majorinfo` VALUES (38, '02', '国际经济与贸易', '08', '经济与管理学院');
INSERT INTO `majorinfo` VALUES (39, '03', '市场营销', '08', '经济与管理学院');
INSERT INTO `majorinfo` VALUES (40, '04', '电子商务', '08', '经济与管理学院');
INSERT INTO `majorinfo` VALUES (41, '05', '数字经济', '08', '经济与管理学院');

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
  `majorid` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `instituteid` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `institute` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `joinyear` year NULL DEFAULT NULL,
  PRIMARY KEY (`studentid`) USING BTREE,
  INDEX `majorid2`(`majorid`) USING BTREE,
  INDEX `instituteid3`(`instituteid`) USING BTREE,
  CONSTRAINT `instituteid3` FOREIGN KEY (`instituteid`) REFERENCES `instituteinfo` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `majorid2` FOREIGN KEY (`majorid`) REFERENCES `majorinfo` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of studentinfo
-- ----------------------------
INSERT INTO `studentinfo` VALUES ('19010101', '1', '张三', '女', '2012-01-23', '01', '04', '计算机与信息工程学院', 2019);
INSERT INTO `studentinfo` VALUES ('19040102', '123456', 'aaa', '男', '2000-01-01', '01', '04', '计算机与信息工程学院', 2019);
INSERT INTO `studentinfo` VALUES ('19040103', '123454', 'b', '1', '2012-01-23', '01', '04', '计算机与信息工程学院', 2019);
INSERT INTO `studentinfo` VALUES ('19040104', '123453', 'c', '1', '2012-01-23', '01', '04', '计算机与信息工程学院', 2019);
INSERT INTO `studentinfo` VALUES ('19040105', '19010104', '张委员', '男', '2000-01-06', '01', '04', '计算机与信息工程学院', 2019);
INSERT INTO `studentinfo` VALUES ('19040106', '19010105', '张巍远', '男', '2001-04-22', '01', '04', '计算机与信息工程学院', 2019);
INSERT INTO `studentinfo` VALUES ('19040107', '19040420', '郭震源', '男', '2001-04-30', '01', '04', '计算机与信息工程学院', 2019);

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
  `authority` set('Normal','Administrator') CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`teacherid`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of teacherinfo
-- ----------------------------
INSERT INTO `teacherinfo` VALUES ('10001', '123456', ' 王强', '男', '副教授', '计算机与信息工程学院', '2023-02-21', 'Administrator');

SET FOREIGN_KEY_CHECKS = 1;
