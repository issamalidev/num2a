php_num2a
=========
إضافة (extension) ل php تعمل كحاضنة (wrapper) لمكتبة التفقيط num2a بحيث يمكن استخدام توابع التفقيط التي تقدمها المكتبة كتوابع php

الترجمة/البناء (Compile)
========================
قبل البدء
---------
بناء أي إضافة (extension) ل php يحتاج إلى تجهيز جميع المكاتب الضرورية لعملية ترجمة/بناء الاضافات. يمكن مراجعة كتب وملفات التوثيق والمساعدة ل php لمعرفة كيفية تجهيز وإعداد بيئة التطوير لترجمة وبناء الاضافات (php extensions). هذه الاضافة أيضاً تعتمد بطبيعة الحال على مكتبة num2a وتعتمد أيضاً على مكتبة glib-2.0 ، لذلك يجب التأكد أن المكاتب (num2a, glib-2.0) مثبتة وموجودة ضمن مسار معروف ل php ما لم يتم الربط مع نسخ ستاتيكية من هذه المكاتب.

ويندوز (Windows)
----------------
لترجمة هذه الاضافة في ويندوز -بعد تجهيز بيئة التطوير التي أشرنا إليها سابقاً- افتح الملف build.bat ادخل قيم مسارات المكاتب المطلوبة لعملية الترجمة/البناء الموجودة في بداية الملف بحسب أماكن تواجدها في جهازك.
PHP_SOURCE_PATH
GLIB2_INCLUDE_PATH
PHP_LIB_PATH
NUM2A_LIB_PATH
WIN_DEP_LIB_PATH
احفظ الملف وقم بتشغيله ليقوم بترجمة/بناء الاضافة، طبعاً يجب أن يكون مترجم مايكروسفت ضمن ال PATH أو يمكن تشغيله من Visual Studio Command Prompt
في حال نجاح الترجمة فإن الاضافة ستترجم وتحفظ في modules\php_num2a.dll
للترجمة والربط مع نسخة num2a ستاتيك يجب اضافة التوجيه STATIC أثناء ترجمة/بناء هذه الاضافة أيضاً (يمكن تعديل ملف build.bat).

لينوكس (Linux)
--------------
بعد تجهيز بيئة التطوير التي أشرنا إليها سابقاً (فقرة "قبل البدء"). (تحتاج أيضاً إلى تثبيت num2a في النظام عن طريق sudo make install)
بعد تجهيز البيئة انتقل إلى مجلد الاضافة php_num2a ثم قم بتشغيل الأوامر:
phpize
./configure --enable-num2a
make
في حال نجاح الترجمة فإن الاضافة ستترجم وتحفظ في modules/php_num2a.so


التثبيت
=======
لتتمكن من تثبيت وتشغيل php_num2a يجب التأكد أن المكاتب (num2a, glib-2.0) مثبتة وموجودة ضمن مسار معروف ل php -طبعاً هذا إذا لم تقم بالربط مع نسخة ستاتيكية من هذه المكاتب- يمكن الاستعانة بصفحة info.php (أو بتابع phpinfo) لمعرفة المسارات التي ستتعامل معها، ولمعرفة مكان وجود ملف php.ini الذي ستسخدمه أيضاً في عملية التثبيت.

ويندوز (Windows)
----------------
انسخ ملف الاضافة php_num2a.dll إلى مجلد الاضافات المعتمد لدى php (يمكن مراجعة نتيجة تابع phpinfo لمعرفة هذا المسار extension_dir )، عادة المسار الافتراضي في ويندوز هو php\ext.
قم بفتح ملف php.ini وضمن قسم Dynamic Extensions  اضف السطر:
extension=php_num2a.dll
أعد تشغيل سيرفر الاباتشي.

لينوكس (Linux)
--------------
راجع نتيجة التابع phpinfo لمعرفة مسار الاضافات  extension_dir المعتمد لدى نسخة php المثبتة لديك.
انسخ ملف الاضافة php_num2a.so إلى مسار الاضافات.
راجع نتيجة تابع phpinfo لمعرفة مسار ملف php.ini (ابحث عن قيمة المتحول Loaded Configuration File).
قم بفتح ملف php.ini وضمن قسم Dynamic Extensions  اضف السطر:
extension=php_num2a.so
أعد تشغيل سيرفر الاباتشي.
sudo service apach2 restart


