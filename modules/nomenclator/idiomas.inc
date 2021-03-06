<?php
    #         ____
    #        / __/________  ___        ____ _____ _   __
    #       / /_ / ___/ _ \/ _ \______/ __ `/ __ \ | / /
    #      / __// /  /  __/  __/_____/ /_/ / /_/ / |/ /
    #     /_/  /_/   \___/\___/      \__, /\____/|___/   > http://free-gov.org
    #                               /____/
    #
    #  This file is part of 'Free-gov' - modules/nomenclator/idiomas.inc
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


echo <<<EOF
<h1>Listado de Idiomas</h1>
EOF;
 

        $params['searchtable']  = 'nomenclator_idiomas';
        $params['labelslist']   = array ('Nombre del Idioma'=>500, 'Subfijo del Idioma'=>0 );
        $params['fieldslist']   = array('name', 'suffix');
        $params['controls']     = array ('edit',  'delete');
        $params['fieldsearch']  = array('name'=>'Nombre');

        FG_list ($params);

