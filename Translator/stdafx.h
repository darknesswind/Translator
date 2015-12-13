#pragma once
#include <QString>
#include <QMessageBox>
#include <QMap>
#include <QDateTime>
#include <QLocale>

#include <cassert>
#include <memory>

#define QSTR_Error QObject::tr("Error")
#define QSTR_Err_OpenFailed QObject::tr("Open file \"%1\" failed!")
#define QSTR_Err_MkPathFailed QObject::tr("Make path \"%1\" failed!")
#define QSTR_Ask_FileExist QObject::tr("File \"%1\" always exist! Overwrite?")
#define QSTR_ProjectExt QString(".trproj")
