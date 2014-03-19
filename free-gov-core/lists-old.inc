<?php
    //////////////////////////////////////////////////////////////////////////
    // LIST FUNCTIONS (other functions are loaded when first call to FG_list)
    /*

     Required fields:
      V  $params['searchtable']  string
      V  $params['labelslist']   array
      V  $params['fieldslist']   array
      V  $params['controls']     array
      V  $params['fieldsearch']  array
        
      V  $params['where_cond']  string
      V  $params['value']    // ignored for this control
      V  $params['crud_no_add'] 
      V  $params['crud_no_search'] 

      V  $params['orderby'] 
      V  $params['order'] 
    */ 
    //////////////////////////////////////////////////////////////////////////
    function FG_list_old ($params) {
        global $_FG;
        include_once(CORE_PATH . '/lists.inc');
   
        $FG_searchcond = array ('CONTENGA', '=', '>', '<', '>=', '<='); // Search operations array
        $where_cond = ' ' . $params['where_cond'];
        if (!isset($params['controls']))  $params['controls'] = array();

        $stra = explode('_', $params['searchtable']);
        $_FG['baselink'] = $stra[1];


if($params['crud_no_search']!==TRUE){
        $_FG['render']['extrahead'] .= <<<EOF
<script type="text/javascript" src="/js/jquery.jcollapser-1.2.2.js"></script>
<script type="text/javascript" src="/js/jquery.cookie.js?format=txt"></script>
<script type="text/javascript">
    $(function() {
        $("#search").jcollapser({target:'#search1', state:'collapsed'});
    });
</script>
<style type="text/css">
.collapse {
    background: transparent url('/images/list/1/hide-trans.png') no-repeat scroll 0% 0%;
    height: 16px;
    position: relative;
    width: 16px;
}
.expand {
    background:transparent url('/images/list/1/search.png') no-repeat scroll 0% 0%;
    display:none;
    height:16px;
    position:relative;
    width:63px;
}
</style>
<script>$(document).ready( function() { $("#form1").validationEngine('attach'); });</script>
<script>$(document).ready(function(){
		$('.shl').hover(function(){
			$(this).children().addClass('datahighlight');
		},function(){
			$(this).children().removeClass('datahighlight');
		});
});</script>
EOF;
}


        echo <<<EOF
<div id="confirmDelete" title="Confirmación de borrado">
<p><span class="ui-icon ui-icon-circle-close" style="float:left; margin:0 7px 20px 0;"></span> 
 ¿confirma que desea borrar este registro?</p></div>
<script type="text/javascript">
$("#confirmDelete").dialog({ modal: true, bgiframe: true, width: 400, height: 200, autoOpen: false, draggable: false, resizable: false }); 
function confirmDelete(delUrl) { $('#confirmDelete').dialog('option', 'buttons', { "No borrarlo, me arrepentí...": function() { $(this).dialog("close"); },
"Borrar": function() { window.location.href = delUrl; }  }); $('#confirmDelete').dialog('open'); }
</script>
EOF;

        // search environment
        if($params['crud_no_search']!==TRUE){
        if ($_FG['request'][2]==$params['searchtable'].'_removefilter') { unset ($_GET[$params['searchtable'].'_fl']); unset ($_GET[$params['searchtable'].'_va']); unset ($_GET[$params['searchtable'].'_op']); unset ($_SESSION[$params['searchtable'].'search']); }  // process search filter removal

        foreach ($params['fieldsearch'] as $field=>$label)  $select .= '<option value=' . $field . '>' . $label  . '</option>';
        foreach ($FG_searchcond as $i=>$field)    $select2 .= '<option value=' . $i . '>' . $field  . '</option>';
        if (isset($_GET[$params['searchtable'].'_fl'])) { $_SESSION[$params['searchtable'].'search']['fl'] = $_GET[$params['searchtable'].'_fl'];  $_SESSION[$params['searchtable'].'search']['op'] = $_GET[$params['searchtable'].'_op']; $_SESSION[$params['searchtable'].'search']['va'] = $_GET[$params['searchtable'].'_va'];  }
        
        $where_cond = '';
        if (isset($_SESSION[$params['searchtable'].'search']['fl'])){
            if ($_SESSION[$params['searchtable'].'search']['op'] == '0') { // search tipe is "CONTAINS"
                $where_cond = ' WHERE `' . $_SESSION[$params['searchtable'].'search']['fl'] . "` LIKE '%" . $_SESSION[$params['searchtable'].'search']['va'] . "%'";
            }
            else {
                $where_cond = ' WHERE `' . $_SESSION[$params['searchtable'].'search']['fl'] . '` ' . $FG_searchcond[$_SESSION[$params['searchtable'].'search']['op']] . " '" . $_SESSION[$params['searchtable'].'search']['va'] . "' ";
            }
        $searchbar = '<tr><td align="center" bgcolor="#CFCFFF"><a href="' . '/'.$_FG['request'][0].'/'. $_FG['request'][1] . '/'.$params['searchtable'] .'_removefilter' . '" title="remover filtro"><img src="/images/list/1/delete_16-trans.png" width=16 height=16 border=0></a> FILTRADO ACTIVO: <b>' . $params['fieldsearch'][$_SESSION[$params['searchtable'].'search']['fl']]  . '</b> ' .  $FG_searchcond[$_SESSION[$params['searchtable'].'search']['op']] . ' <b>' . $_SESSION[$params['searchtable'].'search']['va'] . '</b></td></tr>';
        }
        }



        // pagination environment
        $resultsperpage = 10;
        if (isset($_FG['request'][2])) { if (!is_numeric($_FG['request'][2])) $reqpage=1; else $reqpage=$_FG['request'][2]; }
        else $reqpage=1;
        $jump =  ($reqpage-1) * $resultsperpage; // how many results to jump over?          
        $countresult = mysqli_query($_FG['db0'], 'SELECT COUNT(*) FROM `' . $params['searchtable'] . '`' . $where_cond);
        $buffertotal = mysqli_fetch_assoc($countresult);  mysqli_free_result($countresult);
        $resulttotal = $buffertotal['COUNT(*)'];
        $from = $jump + 1;
        $to  = $from + ($resultsperpage -1);   
        if ($to > $resulttotal) $to = $resulttotal; 

        if ($resulttotal > 0)
        $pagination = '<center> RESULTADOS: '.$resulttotal.' &nbsp; | &nbsp; Mostrando del '.$from.' al '.$to . ' &nbsp; | &nbsp; &nbsp; &nbsp;' . FGpaginate($reqpage, 
                $resulttotal, $resultsperpage, '/'.$_FG['request'][0].'/'.$_FG['request'][1].'/', 20) . '</center>';
        else $pagination = '<center> RESULTADOS: '.$resulttotal. ' (no hay registros disponibles)';




        // "order by" environment
        // TODO

        // back to this page after deletion/modification
        $_SESSION['pageback'] = '/'.$_FG['request'][0].'/'.$_FG['request'][1].'/'.$_FG['request'][2].'/';

        // results table building
        $numfields = count ($params['labelslist']);
        if ($numfields<1) return;

        $numcontrols = count($params['controls']);
        if ($numcontrols>0) {
            $controlswidth = $numcontrols * 24;
            $controlshead = '<td colspan="'.$numcontrols.'" width='.$controlswidth.'>';
        }
        else $controlshead ='';


        echo '<center>';

        if($params['crud_no_search']!==TRUE){
echo <<<EOF
<table width=830 cellpadding=2 cellspacing=2 border=0><tr><td>
<div>
    <fieldset id="search">
    <div class="collapse" ></div>
    <div class="expand" ></div>
    <div id="search1">
<center><form id="form1" action="/{$_FG['request'][0]}/{$_FG['request'][1]}/" method="GET" enctype="multipart/form-data"><table width=830 cellpadding=2 cellspacing=2 border=0><tr><td align="center" bgcolor="#cfcfff"><select name="{$params['searchtable']}_fl" id="{$params['searchtable']}_fl">{$select}</select> &nbsp; &nbsp; <select name="{$params['searchtable']}_op" id="{$params['searchtable']}_op">{$select2}</select>  &nbsp; &nbsp; <input type="text" name="{$params['searchtable']}_va"  id="{$params['searchtable']}_va" value="" class="validate[required,minSize[1]] formfield_short"> &nbsp; &nbsp; <input type="submit" name="btn" value="buscar"></td></tr></table></form>
    </div>
    </fieldset> 
</div></td></tr></table>
EOF;
        }

if ($params['crud_no_add']===true) $addregister = '&nbsp;'; else $addregister = '<a href="/'. $_FG['request'][0] .'/' . $_FG['baselink'] . '_c" title="agregar nuevo registro"><img src="/images/list/2/add-trans.png" width=16 height=16 border=0></a>';

//unset ($_SESSION['menu']);
//var_dump($_SESSION); 
//var_dump($_GET);

        echo '<table width=830 cellpadding=2 cellspacing=2 border=0><tr><td align="center" bgcolor="#CFCFFF"><table width="100%" cellpadding=0 cellspacing=0 border=0><tr><td width=20>' . $addregister . '</td><td>'.$pagination . '</td></tr></table></td></tr>' . $searchbar . '</table><table width=830 cellpadding=2 cellspacing=2 border=0 id="listtable"><thead><tr>';
        foreach ($params['labelslist'] as $label => $width){
            if ($width!=0) $txtwidth = ' width=' . $width; else $txtwidth = ''; 
            echo '<td height=30 align="center" bgcolor="#CFCFFF"' . $txtwidth . '><b>' . $label . '</b></td>'; 
            }
        echo $controlshead . '</tr></thead><tbody>';


        if (isset($params['order'])) $ascdesc = ' ' . $params['order']; else $ascdesc = ' ASC';
        $orderby = ''; if (isset($params['orderby']))  $orderby = ' ORDER BY `' . $params['orderby'] . '`' . $ascdesc; 

        $reqfields = FGlist_mkfieldslist ($params['fieldslist']);
        $result = mysqli_query($_FG['db0'], 'SELECT ' . $reqfields . ' FROM `' . $params['searchtable'] . '`' . $where_cond . $orderby . ' LIMIT ' . $jump . ', ' . $resultsperpage  );

//echo 'SELECT ' . $reqfields . ' FROM `' . $params['searchtable'] . '`' . $where_cond . $orderby . ' LIMIT ' . $jump . ', ' . $resultsperpage;

        if (mysqli_num_rows($result)<1) { echo '<tr><td><br>Sin resultados...</td></tr></tbody></table>'; return; } // no results to show

        while($fila = mysqli_fetch_assoc($result))
            FGlist_mkrow ($fila, $params['fieldslist'], $params['controls'], $params['substitutions']);
        mysqli_free_result($result);

        echo <<<EOF
</tbody></table></center>
EOF;

    return $resulttotal;
    }
 
