// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JF
// Source by-file doc: by-file/FolderSelectDialog.md
// UID:000059 | by-class/FolderSelectDialog.md | Completion:95 | Confidence:96
#include "FolderSelectDialog.h"

#include <ctype.h>
#include <string.h>
#include <windows.h>

#include "../MainUiGraph.h"
#include "../controls/ButtonControlPane.h"
#include "../controls/FolderTreePane.h"
#include "../core/RectBounds.h"
#include "../menu/PopupMenuControls.h"

// UID:0003PA | by-memory/0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer.md | Completion:95 | Confidence:98
// FolderSelectDialog RTTI is emitted by the compiler from the class hierarchy.

// UID:0003BF | by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md | Completion:96 | Confidence:98
// FolderSelectDialog vtable views are emitted by the compiler from virtual declarations.

// UID:0003BG | by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md | Completion:94 | Confidence:96
static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";

// UID:00027D | by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md | Completion:94 | Confidence:96
static wchar_t s_driveRootBuffer[] = L"X:\\";

// UID:000457 | by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md | Completion:94 | Confidence:94
FolderSelectDialog::FolderSelectDialog(
    FolderSelectCallback *resultCallback,
    const wchar_t *initialPath)
    : DialogPane(L"", 0x10, 0),
      m_resultCallback(resultCallback)
{
    RectBounds bounds;

    InitRectBounds(&bounds, 16, 16, 66, 32);
    AddControl(new PopupMenuControlPane(this, &bounds));

    InitRectBounds(&bounds, 16, 286, 79, 310);
    AddControl(new ImageButtonControlPane(14, &bounds));
    bounds.Offset(68, 0);
    AddControl(new ImageButtonControlPane(22, &bounds));

    InitRectBounds(&bounds, 0, 0, 300, 316);
    OnCreate(&bounds, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(0, 0);

    wchar_t currentRoot[4];
    memcpy(currentRoot, kDefaultDriveRootLiteral, sizeof(currentRoot));

    char currentDirectory[MAX_PATH];
    GetCurrentDirectoryA(sizeof(currentDirectory), currentDirectory);
    currentRoot[0] = (unsigned char)currentDirectory[0];

    m_folderTreePane = new FolderTreePane(currentRoot);
    InitRectBounds(&bounds, 16, 32, 284, 282);
    m_folderTreePane->OnCreate(
        &bounds, 0, this, g_mainUiLayerSlots.overlayPaneLayerContext);
    m_folderTreePane->OnShow(0, this);

    PopupMenuControlPane *driveList =
        GetChild<PopupMenuControlPane>(0);
    DWORD driveMask = GetLogicalDrives();

    GetCurrentDirectoryA(sizeof(currentDirectory), currentDirectory);
    int selectedDrive = toupper(currentDirectory[0]) - 'A';

    for (int drive = 0; drive < 32; ++drive)
    {
        if (driveMask & (1UL << drive))
        {
            s_driveRootBuffer[0] = (wchar_t)('A' + drive);
            driveList->AppendItem(new StringMenuItem(s_driveRootBuffer));
            if (drive == selectedDrive)
                driveList->SetSelectedIndex(driveList->GetItemCount() - 1);
        }
    }

    SetPendingControl(2);
    if (initialPath)
        m_folderTreePane->SelectNodeByPath(initialPath);
}

// UID:000459 | by-memory/0x004b1920-0x004b1a00.FolderSelectDialogOnCommand.md | Completion:94 | Confidence:95
void FolderSelectDialog::OnControlCommand(int controlIndex, int notifyCode)
{
    if (controlIndex == 1)
    {
        if (m_resultCallback)
        {
            StringBaseW selectedPath;
            m_folderTreePane->BuildSelectedPath(selectedPath);
            m_resultCallback->Invoke(selectedPath);
        }
        CloseDialog();
    }
    else if (controlIndex == 2)
    {
        if (m_resultCallback)
        {
            StringBaseW emptyPath;
            m_resultCallback->Invoke(emptyPath);
        }
        CloseDialog();
    }
    else if (controlIndex == 0 && notifyCode == 10)
    {
        PopupMenuControlPane *driveList =
            GetChild<PopupMenuControlPane>(0);
        StringMenuItem *item =
            static_cast<StringMenuItem *>(
                driveList->GetItem(driveList->GetSelectedIndex()));
        wchar_t rootPath[100];
        item->CopyText(rootPath, 100);
        m_folderTreePane->SetRootNodeName(rootPath);
    }
}

// UID:00045A | by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md | Completion:93 | Confidence:95
void FolderSelectDialog::PopulateDriveList()
{
    PopupMenuControlPane *driveList =
        GetChild<PopupMenuControlPane>(0);
    DWORD driveMask = GetLogicalDrives();

    char currentDirectory[MAX_PATH];
    GetCurrentDirectoryA(sizeof(currentDirectory), currentDirectory);
    int selectedDrive = toupper(currentDirectory[0]) - 'A';

    for (int drive = 0; drive < 32; ++drive)
    {
        if (driveMask & (1UL << drive))
        {
            s_driveRootBuffer[0] = (wchar_t)('A' + drive);
            driveList->AppendItem(new StringMenuItem(s_driveRootBuffer));
            if (drive == selectedDrive)
                driveList->SetSelectedIndex(driveList->GetItemCount() - 1);
        }
    }
}

// UID:00045C | by-memory/0x004b1b20-0x004b1b87.FolderSelectDialogScalarDeletingDestructor.md | Completion:94 | Confidence:96
FolderSelectDialog::~FolderSelectDialog()
{
    delete m_resultCallback;
}
