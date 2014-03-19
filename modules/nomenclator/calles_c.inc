<?php
    #         ____
    #        / __/________  ___        ____ _____ _   __
    #       / /_ / ___/ _ \/ _ \______/ __ `/ __ \ | / /
    #      / __// /  /  __/  __/_____/ /_/ / /_/ / |/ /
    #     /_/  /_/   \___/\___/      \__, /\____/|___/   > http://free-gov.org
    #                               /____/
    #
    #  This file is part of 'Free-gov' - modules/nomenclator/calles_c.inc
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


$_FG['table']          = 'nomenclator_calles'; // nombre de la table mysql
$_FG['edittitle']      = '<h1>Modificar datos del elemento de nomenclator</h1>'; // título de la pantalla cuando estamos editando datos
$_FG['newregtitle']    = '<h1>Ingresar nuevo elemento de nomenclator</h1>'; // título de la pantalla cuando ingresamos nuevo registro
$_FG['editbutton']     = 'Confirmar modificación'; // Texto del boton del formulario cuando estamos en modo edicion
$_FG['newregbutton']   = 'Ingresar elemento';  // Texto del boton del formulario cuando estamos ingresando un nuevo registro



FG_form_start ('form1'); // así se empiezan todos los formularios
FG_form_text ('name', 'Nombre del elemento:', $_FG['updateinfo']['name'], 'required,minSize[2]');

$listacategorias = FG_mkselect ('nomenclator_categorias', $_FG ['updateinfo']['categoria']); 
FG_form_select ('categoria', 'Categoría del elemento:', $listacategorias);

$listaidiomas = FG_mkselect ('nomenclator_idiomas', $_FG ['updateinfo']['idioma']); 
FG_form_select ('idioma', 'Idioma:', $listaidiomas);

$listabarrios = FG_mkselect ('nomenclator_barrios', $_FG['updateinfo']['barrio']); 
FG_form_select ('barrio', 'Barrio:', $listabarrios);

FG_form_textarea_editor ('text', 'Texto mini-web:', $_FG['updateinfo']['text'], 'required'); 
FG_form_submit ('submit', '', $_FG['buttontext']);


if ($_FG['is_reception']){

    if ($_FG['is_update']){
        $retorno = FG_dbupdate ($_FG['table'], $_FG['form1']);
        if ($retorno==FALSE) FG_error ('No se realizó ninguna modificación de datos');
        else FG_ok ('Se modifico el registro', $_SESSION['pageback']);
    }
    else {
        $retorno = FG_dbinsert ($_FG['table'], $_FG['form1'] );
        if ($retorno==FALSE) FG_error ('No se pudo ingresar el registro');
        else FG_ok ('Se insertó nuevo elemento de nomenclator...', '/nomenclator/calles');
    }
}


