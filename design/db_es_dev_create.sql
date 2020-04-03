CREATE DATABASE IF NOT EXISTS es_dev DEFAULT CHARSET utf8 COLLATE utf8_general_ci;

use es_dev;

CREATE TABLE IF NOT EXISTS `t_operator` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `udi` varchar(32) NOT NULL UNIQUE,
  `pwd` char(40) NOT NULL,
  `name` varchar(32) NOT NULL,
  `phone` varchar(128) NOT NULL,
  `gender` tinyint NOT NULL,  -- 0:male 1:female
  `status` tinyint NOT NULL DEFAULT 0, -- 0:normal 1:frozen 2:deleted
  `role` tinyint NOT NULL, -- 1:admin 2:ESUser 4:ClinicUser
  `is_del` tinyint NOT NULL DEFAULT 0,
  KEY `idx_udi` (`udi`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=110001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `t_endoscope` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `udi` varchar(32) NOT NULL UNIQUE,
  `name` varchar(32) NOT NULL,
  `production_time` datetime NOT NULL,
  `maintain_cycle` smallint NOT NULL DEFAULT 0, -- in days
  `service_year` smallint NOT NULL DEFAULT 0, -- in years
  `step` int unsigned NOT NULL DEFAULT 0, -- 0:bind 1:leak 2:wash 3:rinse 4:sterilize 5:ending-rinse 6:dry 7:storage 8:use 9:pre-processing
  `cycle` int(11) NOT NULL DEFAULT 0,
  `status` tinyint NOT NULL DEFAULT 0, -- 0:normal 1:service 2:forbidden
  `is_high_risk` tinyint NOT NULL DEFAULT 0,
  `photo` varchar(128),
  `last_maintain_time` timestamp DEFAULT CURRENT_TIMESTAMP,
  `remark` varchar(256),
  KEY `idx_udi` (`udi`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=120001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `t_device` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `category` tinyint NOT NULL,
  `status` tinyint NOT NULL DEFAULT 0, -- 0:idle 1:running 2:forbidden
  `cycle_count` smallint NOT NULL DEFAULT 0, -- cycle count for the most recent running
  `cycle_date` datetime NOT NULL, -- the last time at when it started
  `cycle_total` int NOT NULL,
  `production_time` datetime NOT NULL,
  `maintain_cycle` smallint NOT NULL DEFAULT 0, -- in days
  `service_year` smallint NOT NULL DEFAULT 0, -- in years
  `last_maintain_time` timestamp DEFAULT CURRENT_TIMESTAMP,
  `remark` varchar(128)
) ENGINE=InnoDB AUTO_INCREMENT=130001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `t_program` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `category` tinyint NOT NULL,
  `name` varchar(32) NOT NULL,
  `remark` varchar(128)
) ENGINE=InnoDB AUTO_INCREMENT=140001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `t_device_programs` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `device_id` int NOT NULL,
  `program_id` int NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=150001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `t_clean_fluid` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `desc` varchar(128)
) ENGINE=InnoDB AUTO_INCREMENT=160001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `t_disinfect_fluid` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `category` tinyint NOT NULL DEFAULT 0, -- 0:one-off;1:reuse
  `rated_count` tinyint NOT NULL DEFAULT 0, -- 0:no rated
  `desc` varchar(128)
) ENGINE=InnoDB AUTO_INCREMENT=170001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `t_reader` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `sn` varchar(32) NOT NULL UNIQUE, 
  `type` tinyint NOT NULL DEFAULT 0, -- 0:flow 1:device 2:pc 3:other
  `status` tinyint NOT NULL DEFAULT 0, -- 0:normal 1:forbidden
  `remark` varchar(128)
) ENGINE=InnoDB AUTO_INCREMENT=180001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `t_storage` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `max` tinyint NOT NULL DEFAULT 0,
  `status` tinyint NOT NULL DEFAULT 0, -- 0:normal 1:forbidden
  `remark` varchar(128)
) ENGINE=InnoDB AUTO_INCREMENT=190001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `t_flow` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `line_no` tinyint NOT NULL DEFAULT 0,
  `category` tinyint NOT NULL, -- 0:manual; 1:auto
  `status` tinyint NOT NULL DEFAULT 0, -- 0:idle 1:running
  `cycle` int unsigned NOT NULL DEFAULT 0,
  `esp_udi` varchar(32) NOT NULL,
  `remark` varchar(128)
) ENGINE=InnoDB AUTO_INCREMENT=200001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `t_flow_step` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `flow_id` varchar(32) NOT NULL,
  `step_id` int unsigned NOT NULL DEFAULT 0,   -- 0:bind 1:leak 2:wash 3:rinse 4:sterilize 5:ending-rinse 6:dry 7:storage 8:use 9:pre-processing
  `reader_id` int NOT NULL DEFAULT 0,
  `fluid` tinyint,
  `remark` varchar(256),
  KEY `idx_reader_id` (`reader_id`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=210001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `t_version` (
  `id` smallint unsigned PRIMARY KEY AUTO_INCREMENT,
  `version` varchar(16) NOT NULL,
  `hash` varchar(128) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

-- Below are flow tables, note that records for flow are snapshots.

CREATE TABLE IF NOT EXISTS `r_bench` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `esp_udi` varchar(32) NOT NULL,
  `esp_cycle` int unsigned NOT NULL DEFAULT 0,
  `esp_name` varchar(32) NOT NULL,
  `op_udi`  varchar(32) NOT NULL,
  `op_name` varchar(32) NOT NULL,
  `bind_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `leak_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `leak_result` tinyint NOT NULL DEFAULT 0, -- 0:normal,1:abnormal
  `leak_remark` varchar(256),
  `clean_id` varchar(32) NOT NULL,
  `clean_name` varchar(32) NOT NULL,
  `clean_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `clean_method` tinyint NOT NULL DEFAULT 0, -- 0:visual,1:Protein,2:ATP
  `clean_result` tinyint NOT NULL DEFAULT 0, -- 0:normal,1:abnormal
  `clean_remark` varchar(256),
  `rinse_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `rinse_result` tinyint NOT NULL DEFAULT 0, -- 0:normal,1:abnormal
  `rinse_remark` varchar(256),
  `flow_category` tinyint NOT NULL, -- 0:manual; 1:auto step1;
  `storage_id` varchar(32) NOT NULL,
  `storage_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `storage_remark` varchar(256),
  KEY `idx_esp_udi_cycle` (`esp_udi`,`esp_cycle`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=310001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `r_device` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `esp_udi` varchar(32) NOT NULL,
  `esp_cycle` int unsigned NOT NULL DEFAULT 0,
  `device_id` int unsigned NOT NULL,
  `device_name` varchar(32) NOT NULL,
  `device_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `device_result` tinyint NOT NULL DEFAULT 0, -- 0:normal,1:abnormal
  `dry_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `dry_remark` varchar(256),
  `device_photo` varchar(128),
  `device_remark` varchar(256),
  KEY `idx_esp_udi_cycle` (`esp_udi`,`esp_cycle`) USING BTREE 
) ENGINE=InnoDB AUTO_INCREMENT=320001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `r_manual` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `esp_udi` varchar(32) NOT NULL,
  `esp_cycle` int unsigned NOT NULL DEFAULT 0,
  `disinfect_id` varchar(32) NOT NULL,
  `disinfect_name` varchar(32) NOT NULL,
  `disinfect_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `disinfect_method` tinyint NOT NULL DEFAULT 0, -- 0:visual
  `disinfect_result` tinyint NOT NULL DEFAULT 0, -- 0:normal,1:abnormal
  `end_leak_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `end_leak_result` tinyint NOT NULL DEFAULT 0, -- 0:normal,1:abnormal
  `dry_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `disinfect_remark` varchar(256),
  `end_leak_remark` varchar(256),
  `dry_remark` varchar(256),
  KEY `idx_esp_udi_cycle` (`esp_udi`,`esp_cycle`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=330001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `r_clinic` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `esp_udi` varchar(32) NOT NULL,
  `esp_cycle` int unsigned NOT NULL DEFAULT 0,
  `esp_name` varchar(32) NOT NULL,
  `op_udi`  varchar(32) NOT NULL,
  `op_name` varchar(32) NOT NULL,
  `use_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `patient_id` int NOT NULL,
  `patient_name` varchar(32) NOT NULL,
  `patient_age` tinyint DEFAULT 0,
  `patient_gender` tinyint(1) DEFAULT 2,  -- 0:male 1:female
  `preprocess_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `patient_remark` varchar(256),
  `preprocess_remark` varchar(256),
  KEY `idx_esp_udi_cycle` (`esp_udi`,`esp_cycle`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=340001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `r_concentration` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `esp_udi` varchar(32) NOT NULL,
  `esp_cycle` int unsigned NOT NULL DEFAULT 0,
  `esp_name` varchar(32) NOT NULL,
  `op_udi`  varchar(32) NOT NULL,
  `op_name` varchar(32) NOT NULL,
  `op_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `result` tinyint NOT NULL DEFAULT 0, -- 0:normal,1:abnormal
  `remark` varchar(256),
  KEY `idx_esp_udi_cycle` (`esp_udi`,`esp_cycle`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=350001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `r_microbial` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `esp_udi` varchar(32) NOT NULL,
  `esp_cycle` int unsigned NOT NULL DEFAULT 0,
  `esp_name` varchar(32) NOT NULL,
  `op_udi`  varchar(32) NOT NULL,
  `op_name` varchar(32) NOT NULL,
  `op_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `result` tinyint NOT NULL DEFAULT 0, -- 0:normal,1:abnormal
  `remark` varchar(256),
  KEY `idx_esp_udi_cycle` (`esp_udi`,`esp_cycle`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=360001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `r_hand` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `op_udi`  varchar(32) NOT NULL,
  `op_name` varchar(32) NOT NULL,
  `op_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `result` tinyint NOT NULL DEFAULT 0, -- 0:normal,1:abnormal
  `remark` varchar(256)
) ENGINE=InnoDB AUTO_INCREMENT=370001 DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `r_env` (
  `id` int unsigned PRIMARY KEY AUTO_INCREMENT,
  `op_udi`  varchar(32) NOT NULL,
  `op_name` varchar(32) NOT NULL,
  `op_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `result` tinyint NOT NULL DEFAULT 0, -- 0:normal,1:abnormal
  `remark` varchar(256)
) ENGINE=InnoDB AUTO_INCREMENT=380001 DEFAULT CHARSET=utf8;