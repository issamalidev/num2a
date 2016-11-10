/*
 * @file gtkExampleLateBinding.c
 * num2a example using gtk and late binding
 * By Issam Ali  issamsoft.com
 */


#include <gtk/gtk.h>
#include <wchar.h>



#define MAX_NUMBER_NAME_LENGTH 2048



#ifdef _WIN32
#define UTF8_TO_WIDECHAR g_utf8_to_utf16
#define WIDECHAR_TO_UTF8 g_utf16_to_utf8
#define UNICHAR gunichar2
#else
#define UTF8_TO_WIDECHAR g_utf8_to_ucs4
#define WIDECHAR_TO_UTF8 g_ucs4_to_utf8
#define UNICHAR gunichar
#endif


typedef wchar_t *(*num2aW_func)(
						double num, 
						const wchar_t *itemName, 
						const wchar_t *itemNameWithTanween,
						const wchar_t *dualItemName,
						const wchar_t *pluralItemName,
						int ig
						);
						
typedef int (*get_num2aW_func)(
						wchar_t *dest,
						size_t dest_len,
						double num, 
						const wchar_t *itemName, 
						const wchar_t *itemNameWithTanween,
						const wchar_t *dualItemName,
						const wchar_t *pluralItemName,
						int ig
						);
								
typedef wchar_t *(*fnum2aW_func)(
						double num, 
						const wchar_t *itemName, 
						const wchar_t *itemNameWithTanween,
						const wchar_t *dualItemName,
						const wchar_t *pluralItemName,
						int ig,
						const wchar_t *fractionalItemName,
						const wchar_t *fractionalItemNameWithTanween,
						const wchar_t *fractionalDualItemName,
						const wchar_t *fractionalPluralItemName,
						int fig,
						int decimalPlace
						);
typedef int (*get_fnum2aW_func)(
						wchar_t *dest,
						size_t dest_len,
						double num, 
						const wchar_t *itemName, 
						const wchar_t *itemNameWithTanween,
						const wchar_t *dualItemName,
						const wchar_t *pluralItemName,
						int ig,
						const wchar_t *fractionalItemName,
						const wchar_t *fractionalItemNameWithTanween,
						const wchar_t *fractionalDualItemName,
						const wchar_t *fractionalPluralItemName,
						int fig,
						int decimalPlace
						);	

typedef void (*n2a_clean_func)(void *ptr);




static void btnNum2aW_clicked(GtkWidget*, gpointer);
static void btnGetnum2aW_clicked(GtkWidget*, gpointer);
static void btnFnum2aW_clicked(GtkWidget*, gpointer);
static void btnGetfnum2aW_clicked(GtkWidget *, gpointer);
static void activate(GtkApplication *, gpointer);


int main(int argc, char **argv)
{
	GtkApplication *app;
	int status = 0;
	
	app = gtk_application_new("num2a.gtkExample", G_APPLICATION_FLAGS_NONE);
	
	
	g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);
	return status;
}

static void btnNum2aW_clicked(GtkWidget* widget, gpointer data)
{
	GtkWidget *txtItemName, *txtItemNameWithTanween, *txtDualItemName, *txtPluralItemName, *cbItemGender,
			  *txtNum, *txtResult ;
	double num;
	int ig;
	GModule      *module;
	num2aW_func num2aW;
	n2a_clean_func n2a_clean;
	UNICHAR *res, *itemName, *itemNameWithTanween, *dualItemName, *pluralItemName;
	gchar *cres;
	GError *error = NULL;
	glong nRead, nWrite;

	txtItemName = g_object_get_data(G_OBJECT(widget), "txtItemName");
	txtItemNameWithTanween = g_object_get_data(G_OBJECT(widget), "txtItemNameWithTanween");	
	txtDualItemName =  g_object_get_data(G_OBJECT(widget), "txtDualItemName");	
	txtPluralItemName = g_object_get_data(G_OBJECT(widget), "txtPluralItemName");	
	cbItemGender = g_object_get_data(G_OBJECT(widget), "cbItemGender");
	txtNum =  g_object_get_data(G_OBJECT(widget), "txtNum");
	txtResult =  g_object_get_data(G_OBJECT(widget), "txtResult");
	ig = gtk_combo_box_get_active(GTK_COMBO_BOX(cbItemGender));
	num = gtk_spin_button_get_value(GTK_SPIN_BUTTON(txtNum));
	
	gtk_entry_set_text(GTK_ENTRY(txtResult), "");
	module = g_module_open("num2a",  G_MODULE_BIND_LAZY);
	if(module)
	{
		if (g_module_symbol (module, "num2aW", (gpointer *)&num2aW) && 
			g_module_symbol(module, "n2a_clean", (gpointer *)&n2a_clean))
		{
			itemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtItemName)), -1, &nRead, &nWrite, &error);
			itemNameWithTanween = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtItemNameWithTanween)), -1, &nRead, &nWrite, &error);
			dualItemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtDualItemName)), -1, &nRead, &nWrite, &error);
			pluralItemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtPluralItemName)), -1, &nRead, &nWrite, &error);
			res = num2aW(
						num,
						itemName,
						itemNameWithTanween,
						dualItemName,
						pluralItemName,
						ig);

			cres = WIDECHAR_TO_UTF8(res, -1, &nRead, &nWrite, &error);	
			gtk_entry_set_text(GTK_ENTRY(txtResult), cres);
			
			g_free(itemName);
			g_free(itemNameWithTanween);
			g_free(dualItemName);
			g_free(pluralItemName);
			g_free(cres);
			n2a_clean(res);
			g_module_close (module);
		}
	}
}

static void btnGetnum2aW_clicked(GtkWidget* widget, gpointer data)
{
	
	GtkWidget *txtItemName, *txtItemNameWithTanween, *txtDualItemName, *txtPluralItemName, *cbItemGender,
			  *txtNum, *txtResult ;
	double num;
	int ig;
	GModule      *module;
	get_num2aW_func get_num2aW;
	n2a_clean_func n2a_clean;
	UNICHAR *itemName, *itemNameWithTanween, *dualItemName, *pluralItemName;
	UNICHAR res[MAX_NUMBER_NAME_LENGTH];
	gchar *cres = NULL;
	GError *error = NULL;
	glong nRead, nWrite;

	txtItemName = g_object_get_data(G_OBJECT(widget), "txtItemName");
	txtItemNameWithTanween = g_object_get_data(G_OBJECT(widget), "txtItemNameWithTanween");	
	txtDualItemName =  g_object_get_data(G_OBJECT(widget), "txtDualItemName");	
	txtPluralItemName = g_object_get_data(G_OBJECT(widget), "txtPluralItemName");	
	cbItemGender = g_object_get_data(G_OBJECT(widget), "cbItemGender");
	txtNum =  g_object_get_data(G_OBJECT(widget), "txtNum");
	txtResult =  g_object_get_data(G_OBJECT(widget), "txtResult");
	ig = gtk_combo_box_get_active(GTK_COMBO_BOX(cbItemGender));
	num = gtk_spin_button_get_value(GTK_SPIN_BUTTON(txtNum));
	
	gtk_entry_set_text(GTK_ENTRY(txtResult), "");
	module = g_module_open("num2a",  G_MODULE_BIND_LAZY);
	if(module)
	{
		
		if (g_module_symbol (module, "get_num2aW", (gpointer *)&get_num2aW) && 
			g_module_symbol(module, "n2a_clean", (gpointer *)&n2a_clean))
		{

			itemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtItemName)), -1, &nRead, &nWrite, &error);
			itemNameWithTanween = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtItemNameWithTanween)), -1, &nRead, &nWrite, &error);
			dualItemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtDualItemName)), -1, &nRead, &nWrite, &error);
			pluralItemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtPluralItemName)), -1, &nRead, &nWrite, &error);

			
			if(get_num2aW(res,MAX_NUMBER_NAME_LENGTH, num, itemName, itemNameWithTanween, dualItemName, pluralItemName,	ig))
			{
				cres = WIDECHAR_TO_UTF8(res, -1, &nRead, &nWrite, &error);	
				gtk_entry_set_text(GTK_ENTRY(txtResult), cres);
			}
			
			g_free(itemName);
			g_free(itemNameWithTanween);
			g_free(dualItemName);
			g_free(pluralItemName);
			if(cres)
				g_free(cres);
			g_module_close (module);
		}
	}
}

static void btnFnum2aW_clicked(GtkWidget* widget, gpointer data)
{
	GtkWidget *txtItemName, *txtItemNameWithTanween, *txtDualItemName, *txtPluralItemName, *cbItemGender,
			  *txtNum, *txtResult ;
	GtkWidget *txtFractionalItemName, *txtFractionalItemNameWithTanween, *txtFractionalDualItemName,
				*txtFractionalPluralItemName, *cbFractionlItemNameGender, *txtDecimalPlace;
	double num;
	int ig, fig, decimalPlace;
	GModule      *module;
	fnum2aW_func fnum2aW;
	n2a_clean_func n2a_clean;

	UNICHAR *res, *itemName, *itemNameWithTanween, *dualItemName, *pluralItemName;
	UNICHAR *fractionalItemName, *fractionalItemNameWithTanween, *fractionalDualItemName,
				*fractionalPluralItemName;
	gchar *cres;
	GError *error = NULL;
	glong nRead, nWrite;

	txtItemName = g_object_get_data(G_OBJECT(widget), "txtItemName");
	txtItemNameWithTanween = g_object_get_data(G_OBJECT(widget), "txtItemNameWithTanween");	
	txtDualItemName =  g_object_get_data(G_OBJECT(widget), "txtDualItemName");	
	txtPluralItemName = g_object_get_data(G_OBJECT(widget), "txtPluralItemName");	
	cbItemGender = g_object_get_data(G_OBJECT(widget), "cbItemGender");
	txtNum =  g_object_get_data(G_OBJECT(widget), "txtNum");
	txtResult =  g_object_get_data(G_OBJECT(widget), "txtResult");
	
	txtFractionalItemName = g_object_get_data(G_OBJECT(widget), "txtFractionalItemName");
	txtFractionalItemNameWithTanween = g_object_get_data(G_OBJECT(widget), "txtFractionalItemNameWithTanween");
	txtFractionalDualItemName = g_object_get_data(G_OBJECT(widget), "txtFractionalDualItemName");
	txtFractionalPluralItemName = g_object_get_data(G_OBJECT(widget), "txtFractionalPluralItemName");
	cbFractionlItemNameGender = g_object_get_data(G_OBJECT(widget), "cbFractionlItemNameGender");
	txtDecimalPlace = g_object_get_data(G_OBJECT(widget), "txtDecimalPlace");
	
	gtk_entry_set_text(GTK_ENTRY(txtResult), "");
	module = g_module_open("num2a",  G_MODULE_BIND_LAZY);
	if(module)
	{
		if (g_module_symbol (module, "fnum2aW", (gpointer *)&fnum2aW) && 
			g_module_symbol(module, "n2a_clean", (gpointer *)&n2a_clean))
		{
			ig = gtk_combo_box_get_active(GTK_COMBO_BOX(cbItemGender));
			num = gtk_spin_button_get_value(GTK_SPIN_BUTTON(txtNum));

			itemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtItemName)), -1, &nRead, &nWrite, &error);
			itemNameWithTanween = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtItemNameWithTanween)), -1, &nRead, &nWrite, &error);
			dualItemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtDualItemName)), -1, &nRead, &nWrite, &error);
			pluralItemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtPluralItemName)), -1, &nRead, &nWrite, &error);
			fractionalItemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtFractionalItemName)), -1, &nRead, &nWrite, &error);
			fractionalItemNameWithTanween = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtFractionalItemNameWithTanween)), -1, &nRead, &nWrite, &error);
			fractionalDualItemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtFractionalDualItemName)), -1, &nRead, &nWrite, &error);
			fractionalPluralItemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtFractionalPluralItemName)), -1, &nRead, &nWrite, &error);

			fig = gtk_combo_box_get_active(GTK_COMBO_BOX(cbFractionlItemNameGender));
			decimalPlace = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(txtDecimalPlace));
			res = fnum2aW(
						num,
						itemName,
						itemNameWithTanween,
						dualItemName,
						pluralItemName,
						ig,
						fractionalItemName,
						fractionalItemNameWithTanween,
						fractionalDualItemName,
						fractionalPluralItemName,
						fig,
						decimalPlace);
			cres = WIDECHAR_TO_UTF8(res, -1, &nRead, &nWrite, &error);	
			gtk_entry_set_text(GTK_ENTRY(txtResult), cres);
			
			g_free(itemName);
			g_free(itemNameWithTanween);
			g_free(dualItemName);
			g_free(pluralItemName);
			g_free(fractionalItemName);
			g_free(fractionalItemNameWithTanween);
			g_free(fractionalDualItemName);
			g_free(fractionalPluralItemName);
			g_free(cres);
			n2a_clean(res);
			g_module_close (module);
		}
	}
}


static void btnGetfnum2aW_clicked(GtkWidget *widget, gpointer data)
{
	GtkWidget *txtItemName, *txtItemNameWithTanween, *txtDualItemName, *txtPluralItemName, *cbItemGender,
			  *txtNum, *txtResult ;
	GtkWidget *txtFractionalItemName, *txtFractionalItemNameWithTanween, *txtFractionalDualItemName,
				*txtFractionalPluralItemName, *cbFractionlItemNameGender, *txtDecimalPlace;
	double num;
	int ig, fig, decimalPlace;
	GModule      *module;
	get_fnum2aW_func get_fnum2aW;
	n2a_clean_func n2a_clean;
	UNICHAR *itemName, *itemNameWithTanween, *dualItemName, *pluralItemName;
	UNICHAR *fractionalItemName, *fractionalItemNameWithTanween, *fractionalDualItemName,
				*fractionalPluralItemName;
	UNICHAR res[MAX_NUMBER_NAME_LENGTH];
	gchar *cres = NULL;
	GError *error = NULL;
	glong nRead, nWrite;

	txtItemName = g_object_get_data(G_OBJECT(widget), "txtItemName");
	txtItemNameWithTanween = g_object_get_data(G_OBJECT(widget), "txtItemNameWithTanween");	
	txtDualItemName =  g_object_get_data(G_OBJECT(widget), "txtDualItemName");	
	txtPluralItemName = g_object_get_data(G_OBJECT(widget), "txtPluralItemName");	
	cbItemGender = g_object_get_data(G_OBJECT(widget), "cbItemGender");
	txtNum =  g_object_get_data(G_OBJECT(widget), "txtNum");
	txtResult =  g_object_get_data(G_OBJECT(widget), "txtResult");
	
	txtFractionalItemName = g_object_get_data(G_OBJECT(widget), "txtFractionalItemName");
	txtFractionalItemNameWithTanween = g_object_get_data(G_OBJECT(widget), "txtFractionalItemNameWithTanween");
	txtFractionalDualItemName = g_object_get_data(G_OBJECT(widget), "txtFractionalDualItemName");
	txtFractionalPluralItemName = g_object_get_data(G_OBJECT(widget), "txtFractionalPluralItemName");
	cbFractionlItemNameGender = g_object_get_data(G_OBJECT(widget), "cbFractionlItemNameGender");
	txtDecimalPlace = g_object_get_data(G_OBJECT(widget), "txtDecimalPlace");
	
	gtk_entry_set_text(GTK_ENTRY(txtResult), "");
	module = g_module_open("num2a",  G_MODULE_BIND_LAZY);
	if(module)
	{
		if (g_module_symbol (module, "get_fnum2aW", (gpointer *)&get_fnum2aW) && 
			g_module_symbol(module, "n2a_clean", (gpointer *)&n2a_clean))
		{
			ig = gtk_combo_box_get_active(GTK_COMBO_BOX(cbItemGender));
			num = gtk_spin_button_get_value(GTK_SPIN_BUTTON(txtNum));
			
			itemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtItemName)), -1, &nRead, &nWrite, &error);
			itemNameWithTanween = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtItemNameWithTanween)), -1, &nRead, &nWrite, &error);
			dualItemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtDualItemName)), -1, &nRead, &nWrite, &error);
			pluralItemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtPluralItemName)), -1, &nRead, &nWrite, &error);
			fractionalItemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtFractionalItemName)), -1, &nRead, &nWrite, &error);
			fractionalItemNameWithTanween = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtFractionalItemNameWithTanween)), -1, &nRead, &nWrite, &error);
			fractionalDualItemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtFractionalDualItemName)), -1, &nRead, &nWrite, &error);
			fractionalPluralItemName = UTF8_TO_WIDECHAR(gtk_entry_get_text(GTK_ENTRY(txtFractionalPluralItemName)), -1, &nRead, &nWrite, &error);
			
			fig = gtk_combo_box_get_active(GTK_COMBO_BOX(cbFractionlItemNameGender));
			decimalPlace = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(txtDecimalPlace));

			if (get_fnum2aW(res, MAX_NUMBER_NAME_LENGTH, num, itemName, itemNameWithTanween, dualItemName, pluralItemName, ig, fractionalItemName, fractionalItemNameWithTanween,
						fractionalDualItemName, fractionalPluralItemName, fig, 	decimalPlace))
			{
				cres = WIDECHAR_TO_UTF8(res, -1, &nRead, &nWrite, &error);	
				gtk_entry_set_text(GTK_ENTRY(txtResult), cres);
			}
			
			g_free(itemName);
			g_free(itemNameWithTanween);
			g_free(dualItemName);
			g_free(pluralItemName);
			g_free(fractionalItemName);
			g_free(fractionalItemNameWithTanween);
			g_free(fractionalDualItemName);
			g_free(fractionalPluralItemName);
			if(cres)
				g_free(cres);
			g_module_close (module);
		}
	}
}


static void activate(GtkApplication *app, gpointer data)
{
	GtkWidget *window;
	GtkAdjustment *adjst, *adjst2;
	GtkWidget *lbNum, *txtNum;
	
	GtkWidget *lbItemName, *txtItemName, *lbItemNameWithTanween, *txtItemNameWithTanween, *lbDualItemName,
			  *txtDualItemName, *lbPluralItemName, *txtPluralItemName, *lbItemGender, *cbItemGender,
			  *btnNum2aW, *btnGetnum2aW, *btnGetfnum2aW, *boxLeftControls;
	GtkWidget *lbFractionalItemName, *txtFractionalItemName, *lbFractionalItemNameWithTanween, *txtFractionalItemNameWithTanween,
	*lbFractionalDualItemName, *txtFractionalDualItemName, *lbFractionalPluralItemName, *txtFractionalPluralItemName,
	*lbFractionalItemNameGender, *cbFractionlItemNameGender, *lbDecimalPlace, *txtDecimalPlace, *btnFnum2aW, *boxRightControls;
	
	GtkWidget *lbResult, *txtResult;
	
	GtkWidget *grdMain;
	
	window = gtk_application_window_new(app);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	gtk_window_set_title(GTK_WINDOW(window), "num2a-gtkExample /Late Binding");
	grdMain = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(grdMain), 5);
	gtk_grid_set_column_spacing(GTK_GRID(grdMain), 5);


	
	lbNum = gtk_label_new("العدد");
	gtk_misc_set_alignment(GTK_MISC(lbNum),0.0,0.5);
	adjst = gtk_adjustment_new(0, -999999999999999.999999, 999999999999999.999999, 1, 0, 0);
	txtNum = gtk_spin_button_new(adjst, 1, 6);
	gtk_widget_set_hexpand(txtNum, TRUE);	
	gtk_grid_attach(GTK_GRID(grdMain),lbNum, 0, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(grdMain),txtNum, 1, 0, 1, 1);
	
	lbItemName = gtk_label_new("اسم المعدود");
	gtk_misc_set_alignment(GTK_MISC(lbItemName),0.0,0.5);
	txtItemName = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(txtItemName), "ليرة");
	gtk_grid_attach(GTK_GRID(grdMain), lbItemName, 0, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(grdMain), txtItemName, 1, 1, 1, 1);
	
	lbItemNameWithTanween = gtk_label_new("اسم المعدود منوناً");
	gtk_misc_set_alignment(GTK_MISC(lbItemNameWithTanween),0.0,0.5);
	txtItemNameWithTanween = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(txtItemNameWithTanween), "ليرةً");
	gtk_grid_attach(GTK_GRID(grdMain), lbItemNameWithTanween, 0, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(grdMain), txtItemNameWithTanween, 1, 2, 1, 1);
	
	lbDualItemName = gtk_label_new("مثنى المعدود");
	gtk_misc_set_alignment(GTK_MISC(lbDualItemName),0.0,0.5);
	txtDualItemName = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(txtDualItemName), "ليرتان");
	gtk_grid_attach(GTK_GRID(grdMain), lbDualItemName, 0, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(grdMain), txtDualItemName, 1, 3, 1, 1);	
	
	lbPluralItemName = gtk_label_new("جمع المعدود");
	gtk_misc_set_alignment(GTK_MISC(lbPluralItemName),0.0,0.5);
	txtPluralItemName = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(txtPluralItemName), "ليرات");
	gtk_grid_attach(GTK_GRID(grdMain), lbPluralItemName, 0, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(grdMain), txtPluralItemName, 1, 4, 1, 1);	
	
	lbItemGender = gtk_label_new("جنس المعدود");
	gtk_misc_set_alignment(GTK_MISC(lbItemGender),0.0,0.5);
	cbItemGender = gtk_combo_box_text_new();
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cbItemGender), "0", "مذكّر");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cbItemGender), "1", "مؤنّث");
	gtk_combo_box_set_active(GTK_COMBO_BOX(cbItemGender), 1);
	gtk_grid_attach(GTK_GRID(grdMain), lbItemGender, 0, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(grdMain), cbItemGender, 1, 5, 1, 1);		
	
	btnNum2aW = gtk_button_new_with_label("num2aW");
	g_object_set_data(G_OBJECT(btnNum2aW), "txtItemName", txtItemName);
	g_object_set_data(G_OBJECT(btnNum2aW), "txtItemNameWithTanween", txtItemNameWithTanween);	
	g_object_set_data(G_OBJECT(btnNum2aW), "txtDualItemName", txtDualItemName);	
	g_object_set_data(G_OBJECT(btnNum2aW), "txtPluralItemName", txtPluralItemName);	
	g_object_set_data(G_OBJECT(btnNum2aW), "cbItemGender", cbItemGender);
	g_object_set_data(G_OBJECT(btnNum2aW), "txtNum", txtNum);
	g_signal_connect(G_OBJECT(btnNum2aW), "clicked", G_CALLBACK(btnNum2aW_clicked), NULL); 
	boxLeftControls = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	gtk_box_pack_start(GTK_BOX(boxLeftControls), btnNum2aW, FALSE, FALSE, 0);
	btnGetnum2aW = gtk_button_new_with_label("get_num2aW");
	g_object_set_data(G_OBJECT(btnGetnum2aW), "txtItemName", txtItemName);
	g_object_set_data(G_OBJECT(btnGetnum2aW), "txtItemNameWithTanween", txtItemNameWithTanween);	
	g_object_set_data(G_OBJECT(btnGetnum2aW), "txtDualItemName", txtDualItemName);	
	g_object_set_data(G_OBJECT(btnGetnum2aW), "txtPluralItemName", txtPluralItemName);	
	g_object_set_data(G_OBJECT(btnGetnum2aW), "cbItemGender", cbItemGender);
	g_object_set_data(G_OBJECT(btnGetnum2aW), "txtNum", txtNum);
	g_signal_connect(G_OBJECT(btnGetnum2aW), "clicked", G_CALLBACK(btnGetnum2aW_clicked), NULL); 
	gtk_box_pack_start(GTK_BOX(boxLeftControls), btnGetnum2aW, FALSE, FALSE, 0);	
	gtk_grid_attach(GTK_GRID(grdMain), boxLeftControls, 1, 7, 1, 1);	
	
	
	lbFractionalItemName = gtk_label_new("اسم كسر المعدود");
	gtk_misc_set_alignment(GTK_MISC(lbFractionalItemName),0.0,0.5);
	txtFractionalItemName = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(txtFractionalItemName), "قرش");
	gtk_widget_set_hexpand(txtFractionalItemName, TRUE);
	gtk_grid_attach(GTK_GRID(grdMain), lbFractionalItemName, 2, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(grdMain), txtFractionalItemName, 3, 1, 1, 1);	
	
	lbFractionalItemNameWithTanween = gtk_label_new("اسم كسر المعدود منوناً");
	gtk_misc_set_alignment(GTK_MISC(lbFractionalItemNameWithTanween),0.0,0.5);
	txtFractionalItemNameWithTanween = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(txtFractionalItemNameWithTanween), "قرشاً");
	gtk_grid_attach(GTK_GRID(grdMain), lbFractionalItemNameWithTanween, 2, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(grdMain), txtFractionalItemNameWithTanween, 3, 2, 1, 1);	
	
	lbFractionalDualItemName = gtk_label_new("مثنى كسر المعدود");
	gtk_misc_set_alignment(GTK_MISC(lbFractionalDualItemName),0.0,0.5);
	txtFractionalDualItemName = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(txtFractionalDualItemName), "قرشان");
	gtk_grid_attach(GTK_GRID(grdMain), lbFractionalDualItemName, 2, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(grdMain), txtFractionalDualItemName, 3, 3, 1, 1);		
	
	lbFractionalPluralItemName = gtk_label_new("جمع كسر المعدود");
	gtk_misc_set_alignment(GTK_MISC(lbFractionalPluralItemName),0.0,0.5);
	txtFractionalPluralItemName = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(txtFractionalPluralItemName), "قروش");
	gtk_grid_attach(GTK_GRID(grdMain), lbFractionalPluralItemName, 2, 4, 1, 1);
	gtk_grid_attach(GTK_GRID(grdMain), txtFractionalPluralItemName, 3, 4, 1, 1);	
	
	lbFractionalItemNameGender = gtk_label_new("جنس كسر المعدود");
	gtk_misc_set_alignment(GTK_MISC(lbFractionalItemNameGender),0.0,0.5);
	cbFractionlItemNameGender = gtk_combo_box_text_new();
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cbFractionlItemNameGender), "0", "مذكّر");
	gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cbFractionlItemNameGender), "1", "مؤنّث");
	gtk_combo_box_set_active(GTK_COMBO_BOX(cbFractionlItemNameGender), 0);
	gtk_grid_attach(GTK_GRID(grdMain), lbFractionalItemNameGender, 2, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(grdMain), cbFractionlItemNameGender, 3, 5, 1, 1);	
	
	lbDecimalPlace = gtk_label_new("خانة كسر المعدود");
	gtk_misc_set_alignment(GTK_MISC(lbDecimalPlace),0.0,0.5);
	adjst2 = gtk_adjustment_new(2, 0, 6, 1, 0, 0);
	txtDecimalPlace = gtk_spin_button_new(adjst2, 1, 0);
	gtk_grid_attach(GTK_GRID(grdMain),lbDecimalPlace, 2, 6, 1, 1);
	gtk_grid_attach(GTK_GRID(grdMain),txtDecimalPlace, 3, 6, 1, 1);
	
	btnFnum2aW = gtk_button_new_with_label("fnum2aW");
	g_object_set_data(G_OBJECT(btnFnum2aW), "txtItemName", txtItemName);
	g_object_set_data(G_OBJECT(btnFnum2aW), "txtItemNameWithTanween", txtItemNameWithTanween);	
	g_object_set_data(G_OBJECT(btnFnum2aW), "txtDualItemName", txtDualItemName);	
	g_object_set_data(G_OBJECT(btnFnum2aW), "txtPluralItemName", txtPluralItemName);	
	g_object_set_data(G_OBJECT(btnFnum2aW), "cbItemGender", cbItemGender);
	g_object_set_data(G_OBJECT(btnFnum2aW), "txtNum", txtNum);
	g_object_set_data(G_OBJECT(btnFnum2aW), "txtFractionalItemName", txtFractionalItemName);
	g_object_set_data(G_OBJECT(btnFnum2aW), "txtFractionalItemNameWithTanween", txtFractionalItemNameWithTanween);	
	g_object_set_data(G_OBJECT(btnFnum2aW), "txtFractionalDualItemName", txtFractionalDualItemName);	
	g_object_set_data(G_OBJECT(btnFnum2aW), "txtFractionalPluralItemName", txtFractionalPluralItemName);	
	g_object_set_data(G_OBJECT(btnFnum2aW), "cbFractionlItemNameGender", cbFractionlItemNameGender);
	g_object_set_data(G_OBJECT(btnFnum2aW), "txtDecimalPlace", txtDecimalPlace);
	g_signal_connect(G_OBJECT(btnFnum2aW), "clicked", G_CALLBACK(btnFnum2aW_clicked), NULL); 
	boxRightControls = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	gtk_box_pack_start(GTK_BOX(boxRightControls), btnFnum2aW, FALSE, FALSE, 0);
	btnGetfnum2aW = gtk_button_new_with_label("get_fnum2aW");
	g_object_set_data(G_OBJECT(btnGetfnum2aW), "txtItemName", txtItemName);
	g_object_set_data(G_OBJECT(btnGetfnum2aW), "txtItemNameWithTanween", txtItemNameWithTanween);	
	g_object_set_data(G_OBJECT(btnGetfnum2aW), "txtDualItemName", txtDualItemName);	
	g_object_set_data(G_OBJECT(btnGetfnum2aW), "txtPluralItemName", txtPluralItemName);	
	g_object_set_data(G_OBJECT(btnGetfnum2aW), "cbItemGender", cbItemGender);
	g_object_set_data(G_OBJECT(btnGetfnum2aW), "txtNum", txtNum);
	g_object_set_data(G_OBJECT(btnGetfnum2aW), "txtFractionalItemName", txtFractionalItemName);
	g_object_set_data(G_OBJECT(btnGetfnum2aW), "txtFractionalItemNameWithTanween", txtFractionalItemNameWithTanween);	
	g_object_set_data(G_OBJECT(btnGetfnum2aW), "txtFractionalDualItemName", txtFractionalDualItemName);	
	g_object_set_data(G_OBJECT(btnGetfnum2aW), "txtFractionalPluralItemName", txtFractionalPluralItemName);	
	g_object_set_data(G_OBJECT(btnGetfnum2aW), "cbFractionlItemNameGender", cbFractionlItemNameGender);
	g_object_set_data(G_OBJECT(btnGetfnum2aW), "txtDecimalPlace", txtDecimalPlace);
	g_signal_connect(G_OBJECT(btnGetfnum2aW), "clicked", G_CALLBACK(btnGetfnum2aW_clicked), NULL); 	
	gtk_box_pack_start(GTK_BOX(boxRightControls), btnGetfnum2aW, FALSE, FALSE, 0);
	gtk_grid_attach(GTK_GRID(grdMain), boxRightControls, 3, 7, 1, 1);	
	
	lbResult = gtk_label_new("النتيجة");
	gtk_misc_set_alignment(GTK_MISC(lbResult),0.0,0.0);
	txtResult = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(grdMain), lbResult, 0, 8, 1, 1);
	gtk_grid_attach(GTK_GRID(grdMain), txtResult, 1, 8, 3, 1);	
	g_object_set_data(G_OBJECT(btnNum2aW), "txtResult", txtResult);
	g_object_set_data(G_OBJECT(btnFnum2aW), "txtResult", txtResult);	
	g_object_set_data(G_OBJECT(btnGetnum2aW), "txtResult", txtResult);	
	g_object_set_data(G_OBJECT(btnGetfnum2aW), "txtResult", txtResult);	
	
	gtk_container_add(GTK_CONTAINER(window), grdMain);
	gtk_widget_show_all(window);
	
}

