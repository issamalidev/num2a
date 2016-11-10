<?php
$genders = array(
  '0' => 'مذكّر',
  '1' => 'مؤنّث'
);

$num = isset($_POST['num'])?$_POST['num']:'';
$itemName = isset($_POST['itemName'])?$_POST['itemName']:'ليرة';
$itemNameWithTanween = isset($_POST['itemNameWithTanween'])?$_POST['itemNameWithTanween']:'ليرةً';
$dualItemName = isset($_POST['dualItemName'])?$_POST['dualItemName']:'ليرتان';
$pluralItemName = isset($_POST['pluralItemName'])?$_POST['pluralItemName']:'ليرات';
$itemNameGender = isset($_POST['itemNameGender'])?$_POST['itemNameGender']:'1';

$fractionalItemName = isset($_POST['fractionalItemName'])?$_POST['fractionalItemName']:'قرش';
$fractionalItemNameWithTanween = isset($_POST['fractionalItemNameWithTanween'])?$_POST['fractionalItemNameWithTanween']:'قرشاً';
$fractionalDualItemName = isset($_POST['fractionalDualItemName'])?$_POST['fractionalDualItemName']:'قرشان';
$fractionalPluralItemName = isset($_POST['fractionalPluralItemName'])?$_POST['fractionalPluralItemName']:'قروش';
$fractionalItemNameGender = isset($_POST['fractionalItemNameGender'])?$_POST['fractionalItemNameGender']:'';
$decimalPlace = isset($_POST['decimalPlace'])?$_POST['decimalPlace']:'2';

$result = '';
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
	if(isset($_POST['btnNum2aW']))
	{
		$result = num2a_num2aW( $num, $itemName, $itemNameWithTanween, $dualItemName, $pluralItemName, $itemNameGender);
	}
	if(isset($_POST['btnGetNum2aW']))
	{
		$result = num2a_get_num2aW( $num, $itemName, $itemNameWithTanween, $dualItemName, $pluralItemName, $itemNameGender);
	}

	if(isset($_POST['btnFnum2aW']))
	{
		$result = num2a_fnum2aW( $num, $itemName, $itemNameWithTanween, $dualItemName, $pluralItemName, $itemNameGender,
									$fractionalItemName, $fractionalItemNameWithTanween, $fractionalDualItemName,
									$fractionalPluralItemName, $fractionalItemNameGender, $decimalPlace);
	}
	if(isset($_POST['btnGetFnum2aW']))
	{
		$result = num2a_get_fnum2aW( $num, $itemName, $itemNameWithTanween, $dualItemName, $pluralItemName, $itemNameGender,
									$fractionalItemName, $fractionalItemNameWithTanween, $fractionalDualItemName,
									$fractionalPluralItemName, $fractionalItemNameGender, $decimalPlace);
	}	
}
?>




<html >
<body dir="rtl">
	<form action="" method="post">
		
		<table>
			<tr>
				<td>
					الرقم
				</td>
				<td>
					<input type="text" name="num" value="<?php echo $num?>"> 
				</td>
				<td>
				</td>
				<td>
				</td>
			</tr>
			<tr>
				<td>
					اسم المعدود
				</td>
				<td>
					<input type="text" name="itemName" value="<?php echo $itemName?>"> 
				</td>
				<td>
					اسم كسر المعدود
				</td>
				<td>
					<input type="text" name="fractionalItemName" value="<?php echo $fractionalItemName?>"> 
				</td>
			</tr>
			<tr>
				<td>
					اسم المعدود منوناً
				</td>
				<td>
					<input type="text" name="itemNameWithTanween" value="<?php echo $itemNameWithTanween?>"> 
				</td>
				<td>
					اسم كسر المعدود منوناً
				</td>
				<td>
					<input type="text" name="fractionalItemNameWithTanween" value="<?php echo $fractionalItemNameWithTanween?>">
				</td>
			</tr>
			<tr>
				<td>
					مثنى المعدود
				</td>
				<td>
					<input type="text" name="dualItemName" value="<?php echo $dualItemName?>"> 
				</td>
				<td>
					مثنى كسر المعدود
				</td>
				<td>
					<input type="text" name="fractionalDualItemName" value="<?php echo $fractionalDualItemName?>"> 				
				</td>
			</tr>	
			<tr>
				<td>
					جمع المعدود
				</td>
				<td>
					<input type="text" name="pluralItemName" value="<?php echo $pluralItemName ?>"> 
				</td>
				<td>
					جمع كسر المعدود
				</td>
				<td>
					<input type="text" name="fractionalPluralItemName" value="<?php echo $fractionalPluralItemName ?>"> 
				</td>
			</tr>	
			<tr>
				<td>
					جنس المعدود
				</td>
				<td>
				<select id="itemNameGender" name="itemNameGender" >
					<?php foreach ($genders as $value=>$text){ ?>
					   <option <?php if($value == $itemNameGender){echo 'selected="selected"'; }?> value="<?php echo $value; ?>"><?php echo $text; ?></option>
					<?php } ?>
				</select>
				</td>
				<td>
					جنس كسر المعدود
				</td>
				<td>
				<select id="fractionalItemNameGender" name="fractionalItemNameGender" >
					<?php foreach ($genders as $value=>$text){ ?>
					   <option <?php if($value == $fractionalItemNameGender){echo 'selected="selected"'; }?> value="<?php echo $value; ?>"><?php echo $text; ?></option>
					<?php } ?>
				</select>				
				</td>
			</tr>
			<tr>
				<td>
					
				</td>
				<td>
				
				</td>
				<td>
					خانة كسر المعدود
				</td>
				<td>
					<input type="text" name="decimalPlace" value="<?php echo $decimalPlace ?>"> 
				</td>
			</tr>
			<tr>
				<td>
					
				</td>
				<td>
					<input type="submit" name="btnNum2aW" value="num2aW">
					<input type="submit" name="btnGetNum2aW" value="get_num2aW">
				</td>
				<td>
					
				</td>
				<td>
					<input type="submit" name="btnFnum2aW" value="fnum2aW">
					<input type="submit" name="btnGetFnum2aW" value="get_fnum2aW">
				</td>
			</tr>			
			<tr>
				<td>
					
				</td>
				<td >
				
				</td>
				<td>
				</td>
				<td>
				</td>
			</tr>			
		</table>
	</form>
	<div id="resultDiv">
	<b>
	النتيجة: <?php echo $result;?>
	<b>
	</div>
</body>
</html>



