<?php
    #         ____
    #        / __/________  ___        ____ _____ _   __
    #       / /_ / ___/ _ \/ _ \______/ __ `/ __ \ | / /
    #      / __// /  /  __/  __/_____/ /_/ / /_/ / |/ /
    #     /_/  /_/   \___/\___/      \__, /\____/|___/   > http://free-gov.org
    #                               /____/
    #
    #  This file is part of 'Free-gov' - http-root/public.php
    #
    #  Free-gov - e-government free software system
    #  Copyright (C) 2011 Iris Montes de Oca <http://www.irismontesdeoca.com>
    #  Copyright (C) 2011 Eduardo Glez <http://www.eduardoglez.com>
    #
    #  Free-gov is free software; you can redistribute it and/or modify
    #  it under the terms of the GNU Affero General Public License as published
    #  by the Free Software Foundation; either version 3 of the License, or
    #  (at your option) any later version.
    #
    #  Free-gov is distributed in the hope that it will be useful,
    #  but WITHOUT ANY WARRANTY; without even the implied warranty of
    #  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    #  GNU Affero General Public License for more details.
    #
    #  You should have received a copy of the GNU Affero General Public License
    #  along with Free-gov: see the file 'license.txt'.  If not, write to
    #  the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    #  Boston, MA 02111-1307, USA.
    #
    #   Authors: Iris Montes de Oca <http://www.irismontesdeoca.com>
    #            Eduardo Glez <http://www.eduardoglez.com>
    #  Internet: http://free-gov.org
    #
    #  Registered in the United States Copyright Office on May 18, 2011
    #  Registration Number at the Library of the Congress of the USA: TXu001756584
    #

    #
    #  ESTE CODIGO HA SIDO APORTADO POR EL MUNICIPIO DE MALDONADO
    #  http://www.municipiomaldonado.gub.uy/nomenclator_digital
    #
    #  Programador: Iris Montes de Oca (iris@municipiomaldonado.gub.uy)
    #
        
//    Since this is an isolated script outside of the main framework, we must start importing some data and functions
//    to deal with databases, URIs, etc. Following 3 lines are a subset of the FRONT_CONTROLLER
    define('PUBLIC_PATH', dirname(__FILE__));
    define('CORE_PATH', dirname(PUBLIC_PATH) . '/free-gov-core'); // Configuration & system files    
    include (CORE_PATH . '/core.inc');     // Include core functions, configuration file, db connection, etc.

//    Decode and inspect received parameter
$id = FG_decode ($_GET['i']); 

if (!is_numeric($id) || (count($_GET)!=1))  {
// We are dealing with a nasty visitor: let's redirect him far away... to INTERPOL website
header('Location: http://www.interpol.int/es/Criminalidad/Delincuencia-inform%C3%A1tica/Ciberdelincuencia'); 
// Register the malformed intent, with details about hacking IP, proxy (if any), datetime, query and user agent
FG_log ('PUBLIC_ATTACK', 'Query (FG_coded): ' . FG_encode($_SERVER['REQUEST_URI']) );
}

$data = FG_dbget ('nomenclator_calles', $id);

//$data['barrio'] = FG_id2name ('nomenclator_barrios', $data['barrio']);
//$data['categoria'] = FG_id2name ('nomenclator_categorias', $data['categoria']);
//$data['idioma'] = FG_id2name ('nomenclator_idiomas', $data['idioma']);

$content = "<h1>{$data['name']}</h1> {$data['text']}";
?>

<!DOCTYPE html>
<html lang="es">
<head>
<title>Nomenclator Digital</title>
<link rel="stylesheet" type="text/css" href="css/mobile.css" media="all">
<meta charset="iso-8859-1" /> 
<meta name="description" content="Proyecto Nomenclator Digital" />
<meta name="viewport" content="width=device-width, initial-scale=1.0; maximum-scale=1.0; user-scalable=0;" />
<link rel="shortcut icon" href="/favicon.ico" />
<!-- [if lt IE 9]>
 <script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
<![endif]-->
</head>
<body>   
 <header>
 <h1><img class="fade" alt="comentario" src="images/logo_municipio_maldonado.png" /></h1>
 </header>
 <section id="contenido">
       <article id="sitios-historicos">
       <?php echo $content; ?>
       </article>
 </section>
<footer><?php echo $_FG['render']['footer']; ?></footer>
</body>
</html>