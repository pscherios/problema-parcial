CREATE TABLE `tareas`.`estudiantes` (
  `id_estudiante` BIGINT NOT NULL AUTO_INCREMENT,
  `carnet` NCHAR(40) NULL,
  `nombres` VARCHAR(60) NULL,
  `apellidos` VARCHAR(60) NULL,
  `direccion` VARCHAR(100) NULL,
  `telefono` INT NULL,
  `genero` BIT NULL,
  `email` VARCHAR(70) NULL,
  `fecha_nacimiento` DATE NULL,
  PRIMARY KEY (`id_estudiante`));