# Nomenclator [DISCONTINUADO]       
       
       
       
       ____                                      
        / __/________  ___        ____ _____ _   __
       / /_ / ___/ _ \/ _ \______/ __ `/ __ \ | / /
      / __// /  /  __/  __/_____/ /_/ / /_/ / |/ / 
     /_/  /_/   \___/\___/      \__, /\____/|___/   > http://free-gov.org
                               /____/              

    #
    #  ESTE INSTRUCTIVO HA SIDO APORTADO POR EL MUNICIPIO DE MALDONADO
    #  http://www.municipiomaldonado.gub.uy/nomenclator_digital
    #
    #  Programador: Iris Montes de Oca (iris@municipiomaldonado.gub.uy)
    #

    #  Versión del manual: 1.0 (8/10/2012) 
    
    
    SISTEMA DE NOMENCLATOR DIGITAL 

    CONTENIDO DEL MANUAL

      1) Requisitos del Sistema
      2) Precauciones de Seguridad
      3) Instalación
         3.1) Base de datos
         3.2) Configuración del archivo .configuration
         3.3) Personalización de imágenes y logos
         3.4) php.ini personalizado
         3.5) Diseño de la mini-web pública
      4) Creación inicial de usuarios y passwords
      5) Instalación como módulo en una plataforma Free-gov preexistente
         5.1) Copia del módulo
         5.2) Archivo de aterrizaje
         5.3) Creación del grupo y los permisos ACL
         5.4) El concepto de módulo en el contexto de una plataforma modular
      6) Fundamentos de uso del sistema
         6.1) Subsistema de acceso privado 
              6.1.1) Idiomas
              6.1.2) Barrios
              6.1.3) Categorías
              6.1.4) Elementos
         6.2) Cartelería con códigos QR   
         6.3) Subsistema de acceso público
      7) Registros de actividad (logfiles)  
      8) Licencia del Software
      9) Por qué se eligió PHP como lenguaje para el desarrollo de este sistema


----------------------------------------------------------------------------------



1) REQUISITOS DEL SISTEMA

Para instalar 'Nomenclator Digital' es necesario contar con:
 - Cualquier sistema operativo para servidores (Linux, FreeBSD, Solaris, etc.)
 - Servidor Apache configurado con mod_rewrite y para usar archivos .htaccess
 - PHP version 5.2 o posterior con extensiones mysqli y gdlib
 - MySQL 5 o posterior
 - Un subdominio disponible en exclusividad para la instalación
 - Se recomienda disponer de la herramienta phpMyAdmin

Tenga presente que la instalación de la plataforma Free-gov modifica profundamente
el funcionamiento del servidor Apache en su subdominio. Por tanto es imposible 
hacer que este sistema coexista con alguna página web normal poniéndolo dentro de 
un directorio. Se debe disponer de un subdominio o dominio virtual con una 
estructura propia de directorios:

      http://www.sitioweb.gov/nomenclator  >>  Incorrecto (da errores graves)
      http://nomenclator.sitioweb.gov      >>  Correcto

PHP puede funcionar enlazado al servidor web Apache mediante mod_php, aunque se
recomienda la interfaz 'fastcgi', de mucho mejor performance.

No es necesario instalar previamente la plataforma de Gobierno Electrónico
Free-gov, ya que la misma está incluída y preconfigurada en esta distribución del
software. Si ya se dispone de una plataforma Free-gov, se puede agregar el módulo
'Nomenclator Digital' siguiendo las indicaciones del punto 5 en este mismo manual.

Como última precaución es oportuno aclarar que el proyecto contiene varios 
archivos ocultos (que comienzan con el caracter '.'). Muchos programas de FTP no
pueden ver o copiar estos archivos a menos que se les active la opción "mostrar
archivos ocultos".



2) PRECAUCIONES DE SEGURIDAD

Si sólo va a probar este software, cualquier instalación LAMP o WAMP moderna es
suficiente. Puede instalar fácilmente todo el software necesario desde
un paquete como XAMPP (http://sourceforge.net/projects/xampp/), que preinstala
Apache, Mysql, PHP, etc. de forma unificada y sin esfuerzo.
Pero una implementación de Gobierno Electrónico seria requiere un cortafuegos,
una auditoría de seguridad permanente con honeypots y detección de intrusiones, 
una política de respaldos diarios, de replicación de bases de datos, etc.
La plataforma de gobierno electrónico 'Free-gov' sobre la que se basa este sistema
es totalmente segura en la medida que sea manejada por administradores de sistemas
competentes y conscientes de que deben complementar toda instalación con las
diferentes herramientas de seguridad y respaldos disponibles para su sistema
operativo.
Como dice la documentación de 'Free-gov': "la seguridad de una implementación de
gobierno electrónico es directamente proporcional a la solidez profesional de
su administrador de sistemas"



3) INSTALACION

3.1 - Base de datos - Es necesario crear una serie de tablas en una base de datos 
MySQL. Estas tablas contienen la estructura ACL (permisos de acceso y usuarios),
así como las definiciones del módulo 'Nomenclator Digital'.
Para automatizar la creación inicial de las tablas, se suministra un archivo de
nombre 'nomenclator-digital.sql' en la raíz del proyecto.
Use el archivo 'nomenclator-digital.sql' desde su herramienta de gestión de 
MySQL (phpMyAdmin por ejemplo), ejecute las instrucciones SQL del archivo y se
crearán automáticamente las estructuras de datos necesarias, además de ciertas
configuraciones iniciales preestablecidas.


3.2 - Configuración del archivo .configuration - Este es el archivo principal de 
cconfiguraión del sistema, y se encuentra en la carpeta free-gov-core. Si está 
en una plataforma UNIX (como Linux o FreeBSD) tenga presente que es un archivo 
oculto, y  configure su gestor de archivos y su cliente FTP para mostrar archivos
ocultos. Dentro de .configuration usted deberá configurar la URI del servidor 
MySQL (si el MySQL está en el mismo servidor web, ponga "loclhost", en caso 
contrario ponga el nombre o dirección IP del servidor de bases de datos). También
deberá poner el nombre de la base de datos a usar, el nombre de usuario y password 
de MySQL. Dentro de '.configuration' se puede configurar el texto que se verá en 
el título y en  el pie de cada página. Por último, la configuración de correo 
electrónico no es requerida en la instalación de 'Nomenclator Digital'


3.3 - Personalización de imágenes y logos - En la carpeta 'http-root/images' hay 
una imagen de nombre 'topbanner-trans.png' que es la que aparece en la portada del
Panl de Administración. Puede ser sustituída por otra imagen PNG de las mismas
dimensiones y con el mismo nombre.
También hay un logotipo del municipio 'logo_municipio_maldonado.png'. Puede 
borrarlo y poner un logotipo personalizado, en el mismo entorno de dimensiones. 
Este logo aparece en las mini-webs que se visualizan en los celulares. En el 
apartado 5 se explicará dónde se invoca esta imagen, en la mini-web pública.


3.4 - php.ini personalizado - La plataforma 'Free-gov' usa una configuración de 
PHP especial y optimizada (aunque no es un requerimiento forzoso). Si usted tiene
la posibilidad de manipular el php.ini global del servidor, use el archivo 
'php.ini' que se suministra dentro de la carpeta 'cgi-bin' del proyecto. Si no 
puede cambiar la configuración global de PHP, entonces siga las instrucciones del 
archivo README.txt suministrado en la carpeta 'cgi-bin'. Luego descomente las 
siguientes líneas, que son las primeras instrucciones del archivo .htaccess en la 
raíz de la instalación ("descomentar" o "quitar el comentario" es borrar el 
caracter # que precede la línea):

    #Options +ExecCGI
    #AddHandler php5-cgi .php
    #Action php-cgi /cgi-bin/php-wrapper.fcgi
    #Action php5-cgi /cgi-bin/php-wrapper.fcgi
    
La configuración del php.ini personalizado indicada en este paso no es forzosa, 
pero es clave para un uso más profesional de la plataforma de Gobierno Electrónico 
Free-gov (hay sistemas que en cada petición al front-controller establecen 
variables como zona horaria, nombre de las cookies por defecto, etc. El proyecto
Free-gov entiende que estos valores se deberían establecer sólo una vez durante
la instalación, aligerando el trabajo de CPU de cada petición, lo cual es muy
importante en servidores sujetos a mucha carga).


3.5 - Diseño de la mini-web pública - La mini-web que el público ve en su celular 
al escanear los códigos QR tiene un diseño por defecto, donde sólo es necesario 
cambiar el logotipo del Municipio. El diseño está en el archivo 'public.php' 
dentro de la carpeta 'http-root'. A partir de la línea 70 comienza un compacto
diseño en HTML 5, optimizado para celulares y dispositivos móviles. Cambie el
nombre de la imagen donde dice: "images/logo_municipio_maldonado.png" (línea 85)
y sustitúyalo por la imagen que usted suministre dentro de la misma carpeta 
'images' (como se explicó en el punto 3.3 de este apartado).
NOTA: La mini-web sólo aporta el marco visual a los documentos a mostrar. Los 
contenidos (artículos, fotos, etc.) son volcados dentro de la mini-web 
dinámicamente por el sistema según el código QR con el que se esté accediendo al 
mismo.



4) CREACION INICIAL DE USUARIOS Y PASSWORDS

Los usuarios (funcionarios que tendrán acceso al sistema para ingresar los 
contenidos del nomenclator) se crean en la base de datos, en la tabla 'acl_users'.
Existe un  usuario inicial, de nombre 'usuarioinicial' y cuyo password es 
'cambiarurgente'. Este usuario fue creado en la línea 161 del archivo 
'nomenclator-digital.sql':

INSERT INTO `acl_users` (`id`, `username`, `cryptpass`, `realname`) VALUES
(1, 'usuarioinicial', '7e2a36a3697c83544ce49c35bb5c7bfe8ec50fc6', 'Usuario');

Como se puede ver, en la base de datos no se guardan los passwords, sino una firma
hash (MD5 + SHA2) del mismo, que por razones de seguridad es irreversible.
Al crear un usuario nuevo, se hace desde el administrador de la base de datos (que
puede ser phpMyAdmin, por ejemplo). A cada usuario que se ingrese, se le puede 
poner en el campo de password la cadena 7e2a36a3697c83544ce49c35bb5c7bfe8ec50fc6 
entonces ese usuario tendrá como password la cadena 'cambiarurgente'. El usuario 
deberá ingresar a su cuenta inmediatamente y cambiar el password por uno de su
preferencia, el que a su vez se guardará encriptado. Si un usuario olvida su 
password, el administrador lo podrá resetear volviendo a poner la cadena 
7e2a36a3697c83544ce49c35bb5c7bfe8ec50fc6 para que el usuario acceda por única vez
con el password 'cambiarurgente'.

Luego de creados cada usuario, es necesario manipular una segunda tabla del ACL 
(Access Control List) para hacer que estos usuarios pertenezcan al grupo 
'nomenclator_admin'. Esto se hace en la tabla 'acl_users2groups'. Cada usuario 
-una vez ingresado a la tabla 'acl_users'- tiene un número de ID autoincremental 
asociado. En la tabla 'acl_users2groups' simplemente hay dos campos ('user' y 
'group'), y la llenamos poniendo entradas con el ID de cada usuario, y la cadena 
de grupo 'nomenclator_admin'.  Para ilustrar lo explicado, abajo se muestra la 
línea del archivo 'nomenclator-digital.sql' que establece los permisos del usuario 
'usuarioinicial' (cuyo id es '1'):

  INSERT INTO `acl_users2groups` (`user`, `group`) VALUES
  (1, 'nomenclator_admin');

Si creamos un usuario pero olvidamos darle pertenencia por lo menos a un grupo,
cuando este usuario ingrese al sistema verá un mensaje de error indicando que
no pertenece a ningún grupo y que no tiene permisos para nada (Free-gov usa una
política de seguridad de restricción por defecto apta para Gobierno Electrónico).
  
  
  
5) INSTALACION COMO MODULO EN UNA PLATAFORMA FREE-GOV PREEXISTENTE 
 
Si su organismo ya dispone de una instalación de la plataforma de Gobierno 
Electrónico Free-gov, entonces considere integrar el Sistema 'Nomenclator Digital'
como módulo de su instalación existente.
De esa forma, los usuarios de 'Nomenclator Digital' verán aparecer los comandos
de este software en el menú de su pantalla habitual de Free-gov, y a la vez éste
seguirá inaccesible para los usuarios que no hayan sido explícitamente agregados
al grupo de administradores de 'Nomenclator Digital'.

5.1 - Copia del módulo - en la carpeta 'modules' de su instalación existente de
Free-gov copie la carpeta 'nomenclator' que se halla dentro de la carpeta 'modules'
de esta distribución.

5.2 - Archivo de aterrizaje - Para aquellos funcionarios que tengan acceso a otras 
funciones de su instalación Free-gov, el funcionamiento del sistema no presentará
cambios. Pero los funcionarios que sólo pertenezcan al grupo 'nomenclator_admin'
necesitarán una pantalla "de aterrizaje" donde ingresar cuando entren al sistema.
El aterrizaje de 'Nomenclator Digital' es el archivo 'nomenclator_admin.inc' que 
se halla dentro de las carpetas 'modules/main' Debe copiarlo en la ruta 
'modules/main' de su instalación de Free-gov existente.

5.3 - Creación del grupo y los permisos ACL - Desde el gestor de MySQL (phpMyAdmin)
cree el grupo 'nomenclator_admin' en la tabla de grupos 'acl_groups':

  INSERT INTO `acl_groups` (`name`, `description`) VALUES
  ('nomenclator_admin', 'manage nomenclator');

Ahora debe crear el "mapa" que vincula al grupo con las diferentes operaciones 
permitidas, así como los elementos del menú que se crearán cuando corresponda.
Esto se realiza en la tabla 'acl_groups2res' que mapea los grupos a los recursos a
ser accesados, agregando las reglas para el grupo 'nomenclator_admin'. Ejecute la 
siguiente instrucción SQL:

   INSERT INTO `acl_groups2res` (`group`, `module`, `operation`, 
    `negative`, `menu_group`, `menu_caption`) VALUES
   ('nomenclator_admin', 'nomenclator', 
    'idiomas', 0, 'Configuraciones', 'Idiomas'),
   ('nomenclator_admin', 'nomenclator', 
    'idiomas_c', 0, NULL, NULL),
   ('nomenclator_admin', 'nomenclator', 
    'idiomas_d', 0, NULL, NULL),
   ('nomenclator_admin', 'nomenclator', 
    'categorias', 0, 'Configuraciones', 'Categorí­as'),
   ('nomenclator_admin', 'nomenclator', 
    'categorias_c', 0, NULL, NULL),
   ('nomenclator_admin', 'nomenclator', 
    'categorias_d', 0, NULL, NULL),
   ('nomenclator_admin', 'nomenclator', 
    'barrios', 0, 'Configuraciones', 'Barrios'),
   ('nomenclator_admin', 'nomenclator', 
    'barrios_c', 0, NULL, NULL),
   ('nomenclator_admin', 'nomenclator', 
    'barrios_d', 0, NULL, NULL),
   ('nomenclator_admin', 'nomenclator', 
   'calles', 0, 'Elementos del nomenclator', 'Listar / buscar'),
   ('nomenclator_admin', 'nomenclator', 
    'calles_c', 0, NULL, NULL),
   ('nomenclator_admin', 'nomenclator', 
    'calles_d', 0, NULL, NULL),
   ('nomenclator_admin', 'nomenclator', 
    'calles_f', 0, NULL, NULL);

Por último agregue los usuarios que corresponda al grupo 'nomenclator_admin', 
de esta forma no sólo tendrán acceso al módulo 'Nomenclator Digital' sino que
además aparecerán los enlaces a las diferentes herramientas en el menú del
sistema del usuario. Un ejemplo de cómo agregar los usuarios con IDs 1, 5 y 100:

   INSERT INTO `acl_users2groups` (`user`, `group`) VALUES
   (1, 'nomenclator_admin'),
   (5, 'nomenclator_admin'),
   (100, 'nomenclator_admin');

5.4 - El concepto de módulo en el contexto de una plataforma modular - Free-gov 
fue concebido para permitir que en una misma instalación coexistan una cantidad 
de módulos diversos, permitiendo a cada usuario ver sólo aquellos que 
corresponden a su tarea, y simplificando la tarea de usuarios que requieren el
uso de varias herramientas al centralizarlas todas bajo un mismo proceso de login.
En la URI de un usuario logueado en panel de control podemos ver:
    https://www.sitio.gov/MODULO/OPERACION/PARAMETRO1/PARAMETRO2/PARAMETROn

En nuestro caso MODULO es 'nomenclator', mientras OPERACION puede ser por ejemplo 
'idiomas_c', que es la pantalla desde donde se da de alta (create) un idioma.    



6) FUNDAMENTOS DE USO DEL SISTEMA

'Nomenclator Digital' es un sistema con un subsistema de acceso privado (donde
los funcionarios crean, mantienen y consultan los catálogos de nomenclator) y
un subsistema público (donde los ciudadanos y turistas pueden ver los documentos
y contenidos multimedia asociados a calles, plazas, monumentos, parques, edificios
históricos, etc.)
 
6.1 - Subsistema de acceso privado - Es un Panel de Control donde sólo acceden los
funcionarios autorizados. Desde el Panel de Control se administra una base de 
datos de elementos de nomenclator (calles, plazas, monumentos, parques, etc.).
Como en toda base de datos es posible agregar registros, modificarlos, borrarlos,
generar listados, realizar búsquedas, y visualizar fichas.

  6.1.1 - Idiomas - El Panel de Control permite administrar los idiomas en que se 
  presentarán las fichas (en las ciudades turísticas es recomendable presentar la 
  información de nomenclator en varios idiomas, por tanto éstos pueden ser
  administrados con total libertad). 
  6.1.2 - Barrios - Cada elemento de nomenclator se puede asociar a un barrio o
  zona del municipio. Los barrios son administrables (altas, bajas, modificaciones,
  listados y búsquedas).
  6.1.3 - Categorías - Son los tipos de elementos del nomenclator, también
  administrables. Tienen la siguiente configuración por defecto:

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

  6.1.4 - Elementos - Los elementos del nomenclator son las calles, monumentos, 
  etc. Cada elemento se puede dar de alta en varios idiomas (varias entradas del
  elemento, cada una con un idioma diferente en su registro). Los elementos se
  asocian también a Categorías (6.1.3) y a Barrios (6.1.2). Para cada elemento 
  genera se genera un código QR (ver apartado 6.2).


6.2 - Cartelería con códigos QR - Los códigos QR a imprimir son generados por el 
sistema en tamaño grande, en formato PNG apto para impresión en cartelería.
Las respectivas imágenes con los códigos QR se obtienen cada vez que se accede a
las fichas dentro del subsistema de acceso privado (en modo visualización, con el 
ícono de la lupa a la derecha en el listado de elementos).
Estos códigos contienen las respectivas URIs para acceder al subsistema de acceso
público mostrando la información de cada elemento de nomenclator.


6.3 - Subsistema de acceso público - Es una página web (una mini-web) creada en
HTML 5, por tanto apta para una óptima visualización en celulares, tablets y 
dispositivos móviles en general. Esta página de nombre 'public.php'se encuentra en
la raíz del dominio, y se debe acceder a la misma con un parámetro creado por el
sistema a efectos de recuperar datos específicos desde la base de datos. 
Cada código QR en la vía pública tiene un enlace a esta mini-web pasando el 
parámetro que corresponde a cada elemento del nomenclator, para que el software
responda mostrando la información apropiada.
El subsistema de acceso público procesa, valida y sanea su entrada a fin de evitar
ataques de tipo XSS o de inyección SQL.



7) REGISTROS DE ACTIVIDAD (LOGFILES)

Free-gov guarda los registros de actividad en la tabla 'log' de la base de datos.
Allí registra toda la actividad que se realiza en el sistema: ingreso de usuarios,
cierres de sesión, errores, intentos de ataques, etc. Para cada registro guarda
día y hora detallada, características de la máquina con la que se accede, datos
del uso de un posible servidor proxy (una técnica muy usada por atacantes), etc.
En el caso de ataques, el sistema encripta la cadena usada por el atacante y la
guarda en el registro, junto a la dirección IP del origen del ataque.

Con toda esa información a almacenar, la tabla 'log' puede crecer desmedidamente,
por lo que se recomenda pasar periódicamente los datos a un soporte paralelo para
fines de archivo, y vaciar la tabla para mantener el servidor SQL más libre. 



8) LICENCIA DEL SOFTWARE

Este software se distribuye bajo la misma licencia de Software Libre que utiliza 
la Plataforma de Gobierno Electrónico 'Free-gov' sobre la que fue desarrollado.
Este software se puede descargar, estudiar, modificar, instalar en cuantas PCs se
desee, se puede copiar, se puede dar a terceros con total libertad... la única
restricción que impone la licencia es que cuando Ud. copie el software y se lo
de a un tercero, lo haga acompañado del código fuente del programa, y con las
mismas libertades con que Ud. lo recibió (y bajo la misma licencia).
La licencia es AGPL versión 3 (Affero General Public License), creada por la Free 
Software Foundation y reconocida por OSI (Open Source Initiative).
Una copia en inglés de la licencia acompaña al proyecto en el archivo license.txt
La licencia original en inglés es la que tiene valor legal en todo el mundo, y se
aplica de acuerdo al Derecho Internacional y los tratados internacionales sobre 
Derechos de Autor.

Puede leer más acerca de esta licencia en:
    http://es.wikipedia.org/wiki/GNU_Affero_General_Public_License

Puede acceder al texto oficial completo de la licencia AGPL en:
    http://www.gnu.org/licenses/agpl.html

Al momento de escribir este documento lamentablemente no existían traducciones al
español del texto de la licencia AGPL.



9) POR QUE SE ELIGIO PHP COMO LENGUAJE PARA EL DESARROLLO DE ESTE SISTEMA

Compartimos las mismas razones que el proyecto Free-gov enumera en su sitio:

- PHP es Software Libre, y además de ahorrar costos de licencias, su modelo de
desarrollo Open Source (con decenas de miles de programadores estudiando,
analizando y mejorando el producto) ha hecho de PHP la plataforma de desarrollo
para programación web más sólida y completa del mercado, superando con creces
a cualquier producto comercial.
- PHP actúa como un lenguaje interpretado, y sin embargo es posible compilar
los scripts para mejorar la velocidad de ejecución (ejemplo: Facebook)
- PHP es el más popular de los lenguajes de programación Server-Side, por lo
tanto es más sencillo hallar programadores calificados, colaboradores, etc. 
- PHP es multiplataforma y puede ser usado con cualquier sistema operativo, y
con cualquier servidor web. No estamos forzados a usar un sistema en particular
- PHP es ampliamente usado en las empresas de hosting comercial, por tanto un
sistema en PHP puede ser fácilmente migrado a cualquier servidor externo, aún
los de más bajo costo.
- PHP (cuando está debidamente instalado y configurado) es una plataforma de
extrema seguridad, perfectamente apta para Gobierno Electrónico, tal como lo
demuestra el proyecto Free-gov.
- PHP soporta programación de alto y bajo nivel (tan bajo como sockets TCP/IP)
- PHP está pre-empaquetado con Apache y MySQL por defecto en la mayoría de las 
distribuciones Linux, así como en FreeBSD, OpenBSD, Solaris, etc.
- PHP soporta tanto Programación Orientata a Obejtos (OOP) como Programación
Procedural Estructurada (esta última es la preferida por Free-gov).

PHP es la tecnología elegida por muchos de los sitios web más grandes del mundo:
Yahoo, Wikipedia, Facebook, Youtube, Flickr, Digg, y partes de Google.
PHP también es usado por aproximadamente el 75% de todos los servidores a nivel
mundial.



