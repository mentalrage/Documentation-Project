// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JF
// Source by-file doc: by-file/FolderSelectDialog.md
// UID:000059 | by-class/FolderSelectDialog.md | Completion:95 | Confidence:96
#ifndef NEXUSTK_UI_DIALOGS_FOLDERSELECTDIALOG_H
#define NEXUSTK_UI_DIALOGS_FOLDERSELECTDIALOG_H

#include "../../util/FunctionObjects.h"
#include "../../util/StringBase.h"
#include "../core/DialogPane.h"

class FolderTreePane;

typedef mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > StringBaseW;
typedef FunctionObjectT<StringBaseW> FolderSelectCallback;

class FolderSelectDialog : public DialogPane
{
public:
    FolderSelectDialog(FolderSelectCallback *resultCallback,
                       const wchar_t *initialPath);
    virtual ~FolderSelectDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);

private:
    void PopulateDriveList();

    FolderTreePane *m_folderTreePane;
    FolderSelectCallback *m_resultCallback;
};

#endif
