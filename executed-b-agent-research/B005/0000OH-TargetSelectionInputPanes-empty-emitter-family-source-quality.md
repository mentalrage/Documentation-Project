** TARGET-REPORT-UID:0000OH **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID0000OH TargetSelectionInputPanes Empty-Emitter Family Source-Quality Report

## Finalized Report / Current Recommendation
- Current recommendation: accept a bounded direct UID0000OH empty-emitter closeout for all 24 current `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` empty marker rows.
- Final disposition: 14 rows receive exact formal C++ or exact marker text, 3 scalar deleting destructors become non-emitting compiler wrappers by metadata repair, 6 class/index rows receive formal no-standalone-body marker comments, and the by-file page records the direct family closeout.
- Required action: implementation callback should edit only the listed target/support by-* docs, then run scoped validators and inspect regenerated `TargetSelectionInputPanes.cpp` freshness.
- Confidence: high for range/function/data facts and owner route; medium-high for final original helper/member spelling where source names are inferred from support docs rather than PDB proof.

## Target
- Target UID: `0000OH`
- Target path: `source-3/project-documentation/by-file/TargetSelectionInputPanes.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/0000OH-TargetSelectionInputPanes-empty-emitter-family-source-quality.md`
- Source queue row: `auto-generated/-ag-research-tracker.md` `Files With Empty Emitters`, [UID:0000OH] with 48 total emitters, 24 filled, 24 empty.
- Current generated file checked: `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`, validator command id `000000001369`, refreshed `2026-06-29T22:39:02-04:00`.
- Current by-file score after callback: `COMPLETION:90`, `CONFIDENCE:88`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`, `CANONICAL_OWNER:FILE`. Report-time score before implementation was `89/85`.

## Current Target State
- Existing owner route is correct: `TargetSelectionInputPanes.cpp` owns the shared target-selection pane family, saved-target globals, keyboard selector singleton slots, prompt literals, and feature packet helpers.
- The generated file already emits ItemWho, SpellWho, SelectObject constructor/destructor/key/mouse/object-list children, Item/Spell state setters, TargetObject mouse/object-list children, target mode flags, and the accepted TargetObject raw local-player marker.
- The remaining 24 empty markers are not one issue. They are a mix of missing formal source bodies, missing static declarations, prompt literal placement, raw covered-by marker needs, class/index no-standalone-body markers, and compiler scalar-delete metadata.
- No target/support by-* docs were edited in this report-only pass. No leases were acquired. No validators were run.

## Supervisor Active Recheck
- Current assignment: `B005-report-0000OH-TargetSelectionInputPanes-empty-emitter-family-20260629`, report-only.
- MCP was required and used. `server_health` succeeded against `database='supervisor_resume_20260629'`: `status: ok`, `idb_path: E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `module: NexusTK.exe`, `imagebase: 0x400000`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`, `strings_cache_size: 2067`. `idb_list` showed active session `supervisor_resume_20260629`, worker pid `17592`.
- No split execution was required. The exact child pages already exist; this report recommends source-quality/formal-C++ and metadata repairs only.

## Evidence Checked
- IDA MCP checks: `server_health`, active database/session check, `lookup_funcs`, `analyze_function`, `xrefs_to`, `xref_query`, and `get_bytes` for `0x005afd30`, `0x005afe70`, `0x005afef0`, `0x005affe0`, `0x005b0010`, `0x005b05b0`, `0x005b06f0`, `0x005af4f0`, `0x005af580`, scalar destructor wrappers at `0x005b7bc0`, `0x005b8100`, `0x005b81d0`, prompt strings at `0x00630af0`, `0x00630b10`, `0x00630b78`, globals at `0x0069bf20`, and singleton slots at `0x0069bf60`.
- by-* docs checked: `by-file/TargetSelectionInputPanes.md`; class docs for `ItemWhoInputPane`, `ItemWhoInputPaneState`, `SelectObjectWithKeyboardPane`, `SpellInputPaneState`, `SpellWhoInputPane`, `TargetObjectWithKeyboardPane`; all 24 empty-marker target pages; PacketBuffer, Socket/g_packetSender, LivingObjectPane, ObjectList target-filter support.
- Prior reports searched by UID/address/name/source-family terms: central executed reports and agent research for `0000OH`, `TargetSelectionInputPanes`, `SelectObjectWithKeyboardPane`, `TargetObjectWithKeyboardPane`, `00048D`, `00036U`, `0001ND`, `0001NK`, `0001NL`, `0001L9`, `0001LA`, `0002AB`, `0002A2`, `ItemWhoTargetPromptString`, `KeyboardPromptString`, `scalar deleting destructor`, and `empty emitter`.
- Negative checks: raw SelectObject helper starts `0x005afd50`, `0x005afdc0`, `0x005afe30` are not IDA functions and have zero xrefs; scalar deleting destructor pages have vtable/thunk routes only and duplicate ordinary destructor cleanup plus delete/free branches; prompt literals have data xrefs but Select/Target prompt literals are already emitted inline by constructors.
- No Wave2/Wave3 material was used as evidence.

## IDA MCP Facts
| Item | Current MCP fact | Source-quality impact |
| --- | --- | --- |
| MCP session | `server_health` ok for `supervisor_resume_20260629`, `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready | MCP requirement satisfied; no fallback-only report |
| UID0001LG `0x005afd30` | `sub_5AFD30`, size `0x1f`; resolves `dword_69BF28` through `dword_67A764`, clears highlight if found; callers from SelectObject key/mouse paths | class-scoped Select clear helper body |
| UID0001LH `0x005afe70` | `sub_5AFE70`, size `0x7e`; if event kind `8`, writes MapPane `+0x108=1`, `+0x10c=target`, `+0x110=-1`, sets `byte_69BED9=1`, queues pane close, rewrites key to Tab and restores it | Select forward helper body with exact map-state data flow |
| UID0001LI `0x005afef0` | constructor size `0xee`; LineInputPane base, singleton `dword_69BF64`, prompt, saved target validation, highlight, `dword_69BF2C` store, `byte_69BEDA=0` | TargetObject constructor body |
| UID0001LJ `0x005affe0` | destructor size `0x29`; restores vtables, clears `dword_69BF64`, tail/base cleanup | TargetObject destructor body; base cleanup implicit |
| UID0001LK `0x005b0010` | key handler size `0x1ca`; vtable-only xref `0x0062f40c`; ctype narrow, modifier gate, Escape/space cleanup, `v`/Tab config gate, self/prev/next traversal | TargetObject key-handler body |
| UID00036S `0x005b05b0` | size `0x1f`; resolves `dword_69BF2C` through active MapPane and clears highlight | class-scoped TargetObject clear helper |
| UID00036U `0x005b06f0` | size `0x8a`; callsites `0x005b00ce`, `0x005b00f4`; writes MapPane `+0x108=1`, `+0x10c=target`, `+0x110=*(target+0x178)`, sets `byte_69BEDA`, copies `dword_69BF2C` to `dword_69BF30`, queues close, forwards Tab | TargetObject forward helper body; `GetTargetFilter()` is inline accessor surface for `target+0x178` |
| UID0001L9 `0x005af4f0` | size `0x8b`; writes opcode `0x0f`, action byte, object id, two UInt16BE args, scratch zero at offset `10`, sends length `10`; seven callers | `SendTargetedActionPacket` body |
| UID0001LA `0x005af580` | size `0x6a`; writes opcode `0x1c`, action byte, object id, scratch zero at offset `6`, sends length `6`; five callers | `SendObjectActionPacket` body |
| UID00048D raw starts | `0x005afd50`, `0x005afdc0`, `0x005afe30` are not IDA functions and have zero xrefs; bytes show retained helper-shaped bodies separated by `0xcc` | covered-by marker to active UID0001LD, not standalone source |
| Scalar wrappers | `0x005b7bc0`, `0x005b8100`, `0x005b81d0` have vtable/thunk refs and duplicate ordinary destructor cleanup plus delete/free paths | non-emitting compiler-wrapper metadata repair |
| Prompt bytes | UTF-16 bytes for `Which target?`, Select prompt, Target prompt; Select/Target prompt xrefs are constructor inline literals | UID0003J5 declaration; UID0003J6/UID0003J7 marker-only |
| Static data | `get_bytes 0x0069bf20 size 20` and `0x0069bf60 size 8` return zero-filled data; xrefs tie slots to constructors/handlers/helpers | zero-initialized static declarations; stale `0xffffffff` wording rejected |

## Function / Child Inventory
| Empty marker | Current score | Disposition | Recommended metadata/result |
| --- | --- | --- | --- |
| UID00006X `ItemWhoInputPane` | 88/90 | class/index no-standalone marker | keep owner/emitter, insert marker |
| UID0003J5 ItemWho prompt | 86/92 | static wide prompt declaration | 88/92, position before constructor |
| UID00006Y `ItemWhoInputPaneState` | 87/90 | class/index no-standalone marker | keep score, insert marker |
| UID0000CT `SelectObjectWithKeyboardPane` | 87/88 | class/index no-standalone marker | keep score, insert marker |
| UID0001LG Select clear helper | 86/90 | source-ready helper body | 88/91 |
| UID00048D Select raw nav island | 85/88 | covered-by marker to UID0001LD | 88/89 |
| UID0001LH Select forward Tab helper | 86/90 | source-ready helper body | 88/90 |
| UID0001ND Select scalar deleting dtor | 86/90 | non-emitting compiler wrapper | 89/91, `RECONSTRUCTABLE:FALSE`, blank emitter |
| UID0003J6 Select prompt | 86/92 | inline-literal no-code marker | keep 86/92 |
| UID0000DM `SpellInputPaneState` | 87/90 | class/index no-standalone marker | keep score, insert marker |
| UID0000DX `SpellWhoInputPane` | 87/88 | class/index no-standalone marker | keep score, insert marker |
| UID0001NK SpellWho scalar deleting dtor | 88/90 | non-emitting compiler wrapper | 89/91, `RECONSTRUCTABLE:FALSE`, blank emitter |
| UID0000ED `TargetObjectWithKeyboardPane` | 87/88 | class/index no-standalone marker | keep score, insert marker |
| UID0001LI TargetObject constructor | 88/92 | source-ready constructor | keep 88/92 |
| UID0001LJ TargetObject destructor | 86/90 | source-ready destructor | 88/91 |
| UID0001LK TargetObject key handler | 86/90 | source-ready key handler | 88/90 |
| UID00036S TargetObject clear helper | 86/88 | source-ready helper body | 88/90 |
| UID00036U TargetObject dispatch helper | 86/88 | source-ready helper body | 88/90 |
| UID0001NL TargetObject scalar deleting dtor | 86/90 | non-emitting compiler wrapper | 89/91, `RECONSTRUCTABLE:FALSE`, blank emitter |
| UID0003J7 TargetObject prompt | 86/92 | inline-literal no-code marker | keep 86/92 |
| UID0001L9 targeted-action packet helper | 86/90 | source-ready file helper | 88/90, early helper position |
| UID0001LA object-action packet helper | 86/90 | source-ready file helper | 88/90, early helper position |
| UID0002AB saved target globals | 86/88 | static data declarations | 88/90, early position |
| UID0002A2 keyboard pane singleton slots | 86/88 | static pointer declarations | 88/90, early position |

## Positive Evidence Summary
- UID0000OH is the only direct source-file route that already owns the pane constructors, handlers, packet helpers, saved-target globals, prompt literals, and singleton slots. MapPane, UserPane, LineInputPane, PacketBuffer, Socket, and Config are dependencies, not owners.
- Current generated output already uses the same source-facing names required by the missing blocks: `s_itemWhoTargetId`, `s_spellWhoTargetId`, `s_selectObjectTargetId`, `s_targetObjectTargetId`, `s_selectObjectTargetModeActive`, `s_targetObjectTargetModeActive`, `SendObjectActionPacket`, `SendTargetedActionPacket`, `kWhichTargetPrompt`, `ClearCurrentTarget`, and `ForwardTabKey`.
- MCP confirms modeled live functions for UID0001LG, UID0001LH, UID0001LI, UID0001LJ, UID0001LK, UID00036S, UID00036U, UID0001L9, and UID0001LA. Their callee/global/xref shapes match the proposed source bodies.
- MCP confirms prompt bytes and xrefs: `0x00630af0` is UTF-16 `Which target?`; `0x00630b10` is UTF-16 `Use arrow key to select target then press enter.`; `0x00630b78` is UTF-16 `Use arrow key to select target then press 'v'.`
- MCP confirms `0x0069bf20-0x0069bf34` and `0x0069bf60-0x0069bf68` are zero-filled data in the current IDB. Older wording that implied `0xffffffff` initialization for singleton slots is stale for the current evidence.

## Negative Evidence Summary
- The class pages are not missing executable logic. Their exact method children already emit. The blank class pages only need formal no-standalone-body comments so the generated file no longer reports them as unexplained empty emitters.
- The scalar deleting destructors are not source-authored method bodies. UID0001ND, UID0001NK, and UID0001NL have vtable/thunk routes and duplicate ordinary destructor cleanup plus conditional delete/free logic. They should follow accepted UID0002S4 ItemWho scalar-wrapper precedent: non-emitting metadata repair, not marker or source C++.
- UID00048D raw SelectObject navigation helpers are retained source-shaped bytes, but current MCP finds no IDA function objects and no xrefs to the raw starts. The active vtable key handler UID0001LD carries the self/previous/next behavior inline, so a covered-by marker is safer than standalone raw-helper C++.
- Select and Target prompt strings at UID0003J6 and UID0003J7 should not emit duplicate static declarations because UID0001LB and UID0001LI constructors already emit the exact wide literals inline.
- No IDA DB edits or generated-file edits are needed. The repair is entirely source documentation metadata/formal C++.

## Heuristic / Inference Reanalysis And Validation
- Packet writer names are inferred source-facing names but already documented in PacketBuffer support as `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, and `PacketBufferWriteUInt32BE`. The formal code uses value-first writer calls because PacketBuffer support documents the raw ABI as value first and destination second. The unsent scratch terminator byte is retained in local buffers but excluded from send lengths.
- `g_packetSender->QueueAndSendPacket(packet, len)` is the established source-facing send shape used by packet helper reports. `dword_67A7EC` is a support dependency, not UID0000OH ownership.
- `ClearCurrentTarget` and `ForwardTabKey` are recommended as class-scoped helper methods for SelectObject and TargetObject. The binary helpers take no meaningful receiver in IDA because `this` is not used by the clear helpers and the forward helpers are called from member handlers; class-scoped source methods avoid two colliding file-local `ClearCurrentTarget()` names and match unqualified member calls already present in generated handlers.
- Target-forward field names are inferred. The formal code intentionally writes `g_activeMapPane->m_targetSelectionActive`, `m_targetSelectionObject`, and `m_targetSelectionFilter` directly to mirror exact binary writes at MapPane offsets `+0x108`, `+0x10c`, and `+0x110`. `target->GetTargetFilter()` is a first-draft inline accessor surface for the direct `LivingObjectPane +0x178` load; B010 ObjectList target-filter evidence supports the `targetFilter` naming direction, while LivingObjectPane sprite/config docs cap confidence because the exact field struct name is not final.
- The formal C++ uses late-1999 through mid-2000s source shape: `NULL`, file-scope `static`, `const` locals, ordinary member functions, no `auto`, no lambdas, no range-for, no `std::size`, no initializer-list containers, and no new C++17 helper style.

## Ranked Ownership Analysis
### 1. UID0000OH `TargetSelectionInputPanes.cpp`
- Evidence for: existing by-file route owns all six pane/state classes, saved target globals, singleton slots, prompt literals, target-selection mode flags, and feature packet helpers. Current generated file already emits the sibling methods under this route.
- Evidence against: final original file split may have had separate item/spell/object source files or a small protocol helper. This is a confidence cap only; the active documentation route is already established and direct.
- Decision: keep UID0000OH as direct source file route.

### 2. Individual by-class pages as direct source files
- Evidence for: class pages are direct emitters for exact method children.
- Evidence against: class pages are indices/source declarations, not separate source files; generated path is one UID0000OH file.
- Decision: keep class pages as child owners where already used, but no standalone source-file split.

### 3. PacketBuffer/Socket/MapPane/UserPane/LineInputPane
- Evidence for: packet and map/UI helpers are called heavily from the target-selection code.
- Evidence against: these are generic dependencies. Their APIs are consumed here but do not own feature behavior.
- Decision: reject as direct owners for these 24 markers.

## Source Placement
- Recommended source file: `NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`.
- Static declarations and packet helpers should be positioned before method bodies that use them. Recommended early positions:
  - UID0002AB `EMITTER_POSITION_OPTIONAL:0`
  - UID0002A2 `EMITTER_POSITION_OPTIONAL:1`
  - UID0003J5 `EMITTER_POSITION_OPTIONAL:2`
  - UID0001L9 `EMITTER_POSITION_OPTIONAL:20`
  - UID0001LA `EMITTER_POSITION_OPTIONAL:21`
- Other method and marker bodies can use existing order unless the callback finds a generated ordering issue. Member function definitions do not require order-local prototypes when the class declaration owns the methods.

## First-Draft C++ Recommendation
The following blocks are exact formal `RECONSTRUCTION_CPP CODE` header/block contents to insert after supervisor approval.

### UID00006X `ItemWhoInputPane`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone ItemWhoInputPane class-level source body; exact method and helper children emit this class.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0003J5 `ItemWhoTargetPromptString`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static const wchar_t kWhichTargetPrompt[] = L"Which target?";
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID00006Y `ItemWhoInputPaneState`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone ItemWhoInputPaneState class declaration is emitted here; [UID:0001IJ] emits SetInputModeFlag.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0000CT `SelectObjectWithKeyboardPane`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone SelectObjectWithKeyboardPane class-level source body; exact method and helper children emit this class.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0001LG `SelectObjectWithKeyboardPaneClearCurrentTarget`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SelectObjectWithKeyboardPane::ClearCurrentTarget()
{
    LivingObjectPane *target =
        g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
    if (target != NULL)
        target->SetTargetHighlight(false);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID00048D `SelectObjectWithKeyboardPaneNavigationRawHelpers`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this range is covered by [UID:0001LD][0x005af710-0x005af955.SelectObjectWithKeyboardPaneOnKeyEvent](by-memory/0x005af710-0x005af955.SelectObjectWithKeyboardPaneOnKeyEvent.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0001LH `SelectObjectWithKeyboardPaneForwardTabKey`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SelectObjectWithKeyboardPane::ForwardTabKey(KeyEvent *event)
{
    if (event->kind == kTargetSelectionKeyEvent) {
        LivingObjectPane *target =
            g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
        if (target != NULL) {
            g_activeMapPane->m_targetSelectionActive = true;
            g_activeMapPane->m_targetSelectionObject = target;
            g_activeMapPane->m_targetSelectionFilter = -1;
            s_selectObjectTargetModeActive = true;
        }

        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
    }

    const unsigned char savedKey = event->key;
    event->key = kKeyTab;
    const bool handled = LineInputPane::OnKeyEvent(event);
    event->key = savedKey;
    return handled;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0001ND `SelectObjectWithKeyboardPaneScalarDeletingDestructor`
No formal C++ or marker should be inserted. Recommended metadata repair only:
```text
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: blank
```

### UID0003J6 `SelectObjectKeyboardPromptString`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Prompt literal is emitted inline by [UID:0001LB][0x005af5f0-0x005af6de.SelectObjectWithKeyboardPaneConstructor](by-memory/0x005af5f0-0x005af6de.SelectObjectWithKeyboardPaneConstructor.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0000DM `SpellInputPaneState`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone SpellInputPaneState class declaration is emitted here; [UID:0001II] emits SetInputModeFlag.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0000DX `SpellWhoInputPane`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone SpellWhoInputPane class-level source body; exact method and helper children emit this class.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0001NK `SpellWhoInputPaneScalarDeletingDestructor`
No formal C++ or marker should be inserted. Recommended metadata repair only:
```text
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: blank
```

### UID0000ED `TargetObjectWithKeyboardPane`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone TargetObjectWithKeyboardPane class-level source body; exact method and helper children emit this class.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0001LI `TargetObjectWithKeyboardPaneConstructor`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
TargetObjectWithKeyboardPane::TargetObjectWithKeyboardPane()
    : LineInputPane(NULL)
{
    s_activeTargetObjectWithKeyboardPane = this;

    SetPromptText(L"Use arrow key to select target then press 'v'.");

    LivingObjectPane *target =
        g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);
    if (target == NULL ||
        target->ObjectType() != kLivingObjectType ||
        target->IsTargetingDisabled()) {
        target = g_pUserPane->GetLocalPlayerObject();
    }

    target->SetTargetHighlight(true);
    s_targetObjectTargetId = target->ObjectId();

    SetPaneOrder(NULL, g_pBackPane);
    s_targetObjectTargetModeActive = false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0001LJ `TargetObjectWithKeyboardPaneDestructor`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
TargetObjectWithKeyboardPane::~TargetObjectWithKeyboardPane()
{
    s_activeTargetObjectWithKeyboardPane = NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0001LK `TargetObjectWithKeyboardPaneKeyboardEvent`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool TargetObjectWithKeyboardPane::OnKeyEvent(KeyEvent *event)
{
    const unsigned char key = NarrowKey(event->key);

    if ((event->modifierFlags & 0x03) != 0)
        return true;

    switch (key) {
    case kKeyEscape:
    case kKeySpace:
        if (event->kind == kTargetSelectionKeyEvent) {
            if (g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId) != NULL)
                ClearCurrentTarget();
            s_targetObjectTargetModeActive = false;
            g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        }
        event->key = kKeyEscape;
        LineInputPane::OnKeyEvent(event);
        event->key = key;
        return false;

    case 'v':
        if (!g_pConfig->tabVSwap)
            return true;
        ForwardTabKey(event);
        return true;

    case kKeyTab:
        if (g_pConfig->tabVSwap)
            return true;
        ForwardTabKey(event);
        return true;

    case kKeySelfTarget:
        if (event->kind == kTargetSelectionKeyEvent) {
            LivingObjectPane *oldTarget =
                g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);
            LivingObjectPane *selfTarget = g_pUserPane->GetLocalPlayerObject();
            if (oldTarget != selfTarget) {
                if (oldTarget != NULL)
                    oldTarget->SetTargetHighlight(false);
                selfTarget->SetTargetHighlight(true);
                s_targetObjectTargetId = selfTarget->GetObjectId();
            }
        }
        return true;

    case 'h':
    case 'k':
    case kKeyPrevA:
    case kKeyPrevB:
        if (event->kind == kTargetSelectionKeyEvent) {
            LivingObjectPane *oldTarget =
                g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);
            LivingObjectPane *newTarget;
            if (oldTarget != NULL) {
                newTarget = g_activeMapPane->FindPreviousSelectableObject(oldTarget);
            } else {
                newTarget = g_pUserPane->GetLocalPlayerObject();
            }

            if (oldTarget != newTarget) {
                if (oldTarget != NULL)
                    oldTarget->SetTargetHighlight(false);
                if (newTarget != NULL) {
                    newTarget->SetTargetHighlight(true);
                    s_targetObjectTargetId = newTarget->GetObjectId();
                } else {
                    s_targetObjectTargetId = 0;
                }
            }
        }
        return true;

    case 'j':
    case 'l':
    case kKeyNextA:
    case kKeyNextB:
        if (event->kind == kTargetSelectionKeyEvent) {
            LivingObjectPane *oldTarget =
                g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);
            LivingObjectPane *newTarget;
            if (oldTarget != NULL) {
                newTarget = g_activeMapPane->FindNextSelectableObject(oldTarget);
            } else {
                newTarget = g_pUserPane->GetLocalPlayerObject();
            }

            if (oldTarget != newTarget) {
                if (oldTarget != NULL)
                    oldTarget->SetTargetHighlight(false);
                if (newTarget != NULL) {
                    newTarget->SetTargetHighlight(true);
                    s_targetObjectTargetId = newTarget->GetObjectId();
                } else {
                    s_targetObjectTargetId = 0;
                }
            }
        }
        return true;
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID00036S `TargetObjectWithKeyboardPaneClearCurrentTarget`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void TargetObjectWithKeyboardPane::ClearCurrentTarget()
{
    LivingObjectPane *target =
        g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);
    if (target != NULL)
        target->SetTargetHighlight(false);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID00036U `TargetObjectWithKeyboardPaneDispatchForwardHelper`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool TargetObjectWithKeyboardPane::ForwardTabKey(KeyEvent *event)
{
    if (event->kind == kTargetSelectionKeyEvent) {
        LivingObjectPane *target =
            g_activeMapPane->FindObjectPaneById(s_targetObjectTargetId);
        if (target != NULL) {
            g_activeMapPane->m_targetSelectionActive = true;
            g_activeMapPane->m_targetSelectionObject = target;
            g_activeMapPane->m_targetSelectionFilter = target->GetTargetFilter();
            s_targetObjectTargetModeActive = true;
            s_targetObjectPreviousTargetId = s_targetObjectTargetId;
        }

        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
    }

    const unsigned char savedKey = event->key;
    event->key = kKeyTab;
    const bool handled = LineInputPane::OnKeyEvent(event);
    event->key = savedKey;
    return handled;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0001NL `TargetObjectWithKeyboardPaneScalarDeletingDestructor`
No formal C++ or marker should be inserted. Recommended metadata repair only:
```text
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: blank
```

### UID0003J7 `TargetObjectKeyboardPromptString`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Prompt literal is emitted inline by [UID:0001LI][0x005afef0-0x005affde.TargetObjectWithKeyboardPaneConstructor](by-memory/0x005afef0-0x005affde.TargetObjectWithKeyboardPaneConstructor.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0001L9 `SendTargetedActionPacket`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static int SendTargetedActionPacket(unsigned char action, unsigned int objectId,
    unsigned short argument1, unsigned short argument2)
{
    unsigned char packet[11];

    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(action, packet + 1);
    PacketBufferWriteUInt32BE(objectId, packet + 2);
    PacketBufferWriteUInt16BE(argument1, packet + 6);
    PacketBufferWriteUInt16BE(argument2, packet + 8);
    packet[10] = 0;

    return g_packetSender->QueueAndSendPacket(packet, 10);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0001LA `SendObjectActionPacket`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static int SendObjectActionPacket(unsigned char action, unsigned int objectId)
{
    unsigned char packet[7];

    PacketBufferWriteUInt8(0x1c, packet);
    PacketBufferWriteUInt8(action, packet + 1);
    PacketBufferWriteUInt32BE(objectId, packet + 2);
    packet[6] = 0;

    return g_packetSender->QueueAndSendPacket(packet, 6);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0002AB `TargetSelectionSavedTargetGlobals`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static unsigned int s_spellWhoTargetId = 0;
static unsigned int s_itemWhoTargetId = 0;
static unsigned int s_selectObjectTargetId = 0;
static unsigned int s_targetObjectTargetId = 0;
static unsigned int s_targetObjectPreviousTargetId = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0002A2 `TargetSelectionKeyboardPaneSingletonSlots`
```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static SelectObjectWithKeyboardPane *s_activeSelectObjectWithKeyboardPane = NULL;
static TargetObjectWithKeyboardPane *s_activeTargetObjectWithKeyboardPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Score And Metadata Recommendation
- UID0000OH target page: raise to `COMPLETION:90`, `CONFIDENCE:88`. Rationale: direct empty-emitter family has an implementation-ready disposition for every current marker; confidence remains below final because exact original `.cpp` split and several helper/member names are inferred.
- UID0003J5: raise to `88/92`, keep owner/emitter `0000OH`, set `EMITTER_POSITION_OPTIONAL:2`, insert static prompt declaration.
- UID0002AB: raise to `88/90`, keep owner/emitter `0000OH`, set `EMITTER_POSITION_OPTIONAL:0`, insert five zero-initialized static dwords.
- UID0002A2: raise to `88/90`, keep owner/emitter `0000OH`, set `EMITTER_POSITION_OPTIONAL:1`, insert two `NULL`-initialized static pointers. Also correct support prose to say current MCP bytes are zero-filled, not `0xffffffff`.
- UID0001L9/UID0001LA: raise to `88/90`, keep owner/emitter `0000OH`, set early helper positions `20` and `21`, insert packet helper bodies. Confidence capped by PacketBuffer helper name/signature inference.
- UID0001LG/UID0001LH/UID00036S/UID00036U: raise to `88/90` or `88/91` as listed in the inventory, keep class owner/emitter, insert class-scoped helper bodies. Confidence capped for forward helpers by MapPane field/accessor names.
- UID0001LI: keep `88/92`, insert constructor C++; existing score already reflects strong constructor evidence.
- UID0001LJ: raise to `88/91`, insert destructor C++.
- UID0001LK: raise to `88/90`, insert key handler C++; confidence capped by large switch source spelling and config/member names.
- UID00048D: raise to `88/89`, keep reconstructable/emitter through `0000CT`, insert covered-by marker.
- UID0001ND/UID0001NK/UID0001NL: raise to `89/91`, set `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++. These are compiler scalar deleting destructors and should disappear from generated output.
- Class/index rows UID00006X, UID00006Y, UID0000CT, UID0000DM, UID0000DX, UID0000ED: keep current scores unless supervisor wants a small completion bump; insert exact no-standalone marker comments and preserve child emission routes.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID0000OH remains direct `NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` route for all 24 rows. | High | by-file inventory, generated file, child owner metadata | `by-file/TargetSelectionInputPanes.md` | incorporate | applied: by-file score is `90/88`, closeout note added, final generated file is `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` with UID0000OH header and zero empty markers. |
| C2 | Class/index rows need formal no-standalone marker comments, not executable code. | High | exact method children already emit; class pages are source-route indices | six by-class docs | incorporate | applied: six by-class formal blocks contain the accepted no-standalone comment plus `[[CHILDREN]]`, required by generated output so exact method/helper children still emit through the class route. |
| C3 | UID0003J5 must emit `kWhichTargetPrompt` before ItemWho constructor use. | High | bytes/xrefs for `0x00630af0`, generated constructor uses symbol | UID0003J5 | incorporate | applied: UID0003J5 emits `static const wchar_t kWhichTargetPrompt[] = L"Which target?";` at generated lines 18-19 before ItemWho constructor use at line 57. |
| C4 | UID0003J6 and UID0003J7 should emit inline-literal covered marker comments only. | High | constructors already emit exact literals | UID0003J6, UID0003J7 | incorporate | applied: generated lines 580-581 and 1127-1128 show marker-only inline prompt coverage for SelectObject and TargetObject. |
| C5 | UID0001LG and UID00036S are class-scoped clear helpers. | High | modeled 31-byte functions, target-id lookup plus highlight clear | UID0001LG, UID00036S | incorporate | applied: generated lines 545-552 and 1091-1098 contain `SelectObjectWithKeyboardPane::ClearCurrentTarget` and `TargetObjectWithKeyboardPane::ClearCurrentTarget`. |
| C6 | UID00048D raw island is covered by UID0001LD and has no direct route to raw starts. | High | MCP no functions/no xrefs; active key handler has behavior inline | UID00048D | incorporate | applied: UID00048D score is `88/89` and generated lines 554-555 emit the covered-by UID0001LD marker. |
| C7 | UID0001LH and UID00036U are source-ready forward Tab helpers with exact map-state writes. | Medium-high | modeled functions, callsites, MapPane offset writes, event key rewrite | UID0001LH, UID00036U | incorporate | applied: generated lines 557-578 and 1103-1124 emit both `ForwardTabKey` bodies, including map-state writes and event-key rewrite. |
| C8 | UID0001ND/UID0001NK/UID0001NL are compiler scalar deleting wrappers and should be non-emitting. | High | vtable/thunk refs only; duplicate destructor cleanup plus delete/free; UID0002S4 precedent | three scalar by-memory docs | incorporate | applied: metadata repaired to non-reconstructable/blank emitter/blank formal C++; generated UID counts are `0001ND=0`, `0001NK=0`, `0001NL=0`. |
| C9 | UID0001LI/UID0001LJ/UID0001LK are source-ready TargetObject constructor/destructor/key handler bodies. | High | modeled functions, vtable refs, global/callee evidence | three TargetObject by-memory docs | incorporate | applied: generated lines 850-872, 873-877, and 879 onward contain TargetObject constructor, destructor, and key handler bodies. |
| C10 | UID0001L9/UID0001LA are source-ready file-local packet helpers with unsent scratch terminators. | High | modeled functions, packet writer offsets, send lengths, caller maps | two packet by-memory docs | incorporate | applied: generated lines 21-35 and 37-48 emit packet helpers with scratch terminators `packet[10] = 0` / `packet[6] = 0` and send lengths `10` / `6`. |
| C11 | UID0002AB/UID0002A2 should emit zero-initialized static declarations. | High | current data bytes zero, xrefs from constructors/handlers/helpers | two data by-memory docs | incorporate | applied: generated lines 7-16 emit zero-initialized saved-target globals and `NULL` singleton pointers at early positions `0` and `1`. |
| C12 | Current `0x0069bf60` singleton bytes are zero-filled; older `0xffffffff` prose is stale. | High | current MCP `get_bytes 0x0069bf60 size 8` | UID0002A2 and by-file support note | reject-stale | applied: UID0002A2 and by-file support note now record current zero-fill proof and mark older `0xffffffff` wording stale. |

## Recommended Target Doc Changes
- `by-file/TargetSelectionInputPanes.md`: add a new change entry for this direct UID0000OH report. It should summarize all 24 marker dispositions, record current MCP session `supervisor_resume_20260629`, and raise file score to `90/88`.
- Preserve existing ownership/source-route history. Do not delete prior B004/B005/B008/B009/B013/B014 notes; this report builds on them.
- Add/update source placement note that early static declarations and packet helpers should precede method bodies in generated output.

## Recommended Support Doc Changes
- Six by-class docs: insert the exact no-standalone marker formal blocks and a short change note that child methods/helpers emit source under UID0000OH. Implementation callback adds the required `[[CHILDREN]]` insertion point to those marker blocks so generated output retains exact child method/helper bodies.
- UID0003J5/UID0003J6/UID0003J7: insert exact prompt formal blocks. UID0003J5 emits a declaration; UID0003J6 and UID0003J7 emit inline-literal no-code markers.
- UID0001LG/UID0001LH/UID0001LI/UID0001LJ/UID0001LK/UID00036S/UID00036U/UID0001L9/UID0001LA/UID0002AB/UID0002A2: insert exact formal C++ blocks and update score/metadata as listed.
- UID00048D: insert exact covered-by marker and record no-function/no-xref proof to raw starts.
- UID0001ND/UID0001NK/UID0001NL: perform metadata repair only; do not insert marker comments.
- UID0002A2 support text should reject stale `0xffffffff` initialization wording and preserve current zero-fill proof.

## Open Questions With Attempted Resolution
- Exact original `TargetObject` forward helper field names: resolved enough for first draft as inferred MapPane target-selection fields plus `LivingObjectPane::GetTargetFilter()`. Current evidence proves offsets and values; original spelling remains a confidence cap, not a no-code blocker.
- Exact original packet helper signatures: resolved enough for first draft as `unsigned char`, `unsigned int`, and `unsigned short` arguments. Binary writes low bytes/words and sends fixed lengths; original signedness is not behavior-visible for these packet fields.
- Exact original `.cpp` split: still not final-proof. The active UID0000OH route is already the documented source route and is sufficient for implementation. This caps the by-file confidence at `88`, not child C++ readiness.
- IDA DB renames: not requested and not needed. This report recommends documentation/source reconstruction changes only.

## Validator Results
- Initial scoped validators: `python tools/validator.py --mode file --file <edited by-* file> --apply` ran from `E:\NTK\GhidraBridge\source-3\project-documentation` for the six by-class pages and all edited by-memory pages, then `python tools/validator.py --mode file --file by-file/TargetSelectionInputPanes.md --apply --wait-generated`; command IDs `000000001458` through `000000001482`, timestamps `2026-06-29T23:05:05-04:00` through `2026-06-29T23:05:49-04:00`, exit code `0`, `ok:1` on each file-mode scan.
- Generated-output fix/revalidation: after generated inspection showed child output suppressed by class marker blocks, the six by-class markers were amended with `[[CHILDREN]]` while preserving the accepted no-standalone comments. Revalidated by-class pages with command IDs `000000001485`-`000000001490`, timestamps `2026-06-29T23:10:09-04:00` through `2026-06-29T23:10:18-04:00`, exit code `0`, `ok:1` each.
- Final by-file validator: `python tools/validator.py --mode file --file by-file/TargetSelectionInputPanes.md --apply --wait-generated`, command ID `000000001491`, timestamp `2026-06-29T23:10:20-04:00`, exit code `0`, `ok:1`, `generated_refresh: completed`, `autogen_cpp_update:1`, `generated_refresh_command_id:000000001491`.
- Relevant warnings/side effects: `by-class/SelectObjectWithKeyboardPane.md` reported pre-existing `missing_ref_uid 00035Q`; final generated refresh reported project-wide nonblocking autogen warnings (`autogen_emitter_has_no_code:425`, `autogen_children_marker_missing:18`, `autogen_children_fallback_insert:8`) outside this callback's corrected class markers. Validator-owned side effects refreshed generated C++/metadata and generated reports; no generated files were edited manually.
- Generated inspection: `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` is 41,329 bytes, 1,150 lines, last write `2026-06-29T23:11:01-04:00`, header `validator-command-id:000000001490` / `validator-refreshed-at:2026-06-29T23:10:18-04:00` from deferred generated refresh, and final by-file command `000000001491` completed generated refresh after that state.
- Empty-marker status: `Empty Emitter Marker` count is `0`. UID counts in generated output: present once for UID00006X, UID00006Y, UID0000CT, UID0000DM, UID0000DX, UID0000ED, UID0003J5, UID0003J6, UID0003J7, UID0001LG, UID00048D, UID0001LH, UID00036S, UID00036U, UID0001L9, UID0001LA, UID0002AB, UID0002A2; UID0001LI and UID0001LK appear in body plus marker references; scalar wrappers UID0001ND/UID0001NK/UID0001NL are absent as intended.

## Changed Files
- Modified target/support docs: `by-file/TargetSelectionInputPanes.md`; six by-class pages `ItemWhoInputPane.md`, `ItemWhoInputPaneState.md`, `SelectObjectWithKeyboardPane.md`, `SpellInputPaneState.md`, `SpellWhoInputPane.md`, `TargetObjectWithKeyboardPane.md`; and edited by-memory support pages UID0003J5, UID0003J6, UID0003J7, UID0001LG, UID00048D, UID0001LH, UID0001ND, UID0001NK, UID0001LI, UID0001LJ, UID0001LK, UID00036S, UID00036U, UID0001NL, UID0001L9, UID0001LA, UID0002AB, UID0002A2.
- Modified report: this Agent-B005 report checklist/ledger/result section.
- Validator-owned generated side effects: `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`, generated metadata/reports, and validator backups were refreshed by validator commands only; no generated file was manually edited.

## Implementation Tracking Checklist
- [x] Supervisor validation required before implementation. Proof: user callback accepted this report for bounded implementation.
- [x] Acquire short leases only immediately before editing `by-file/TargetSelectionInputPanes.md`, the six by-class pages, and the listed by-memory support docs; release after edit/validator batch. Proof: edits were made under B005 leases; `tools/leaser/lease.json` now has `"leases": {}` after expiry/clear.
- [x] Update `by-file/TargetSelectionInputPanes.md`: add this direct UID0000OH empty-emitter family closeout note, raise target score to `90/88`, preserve ownership/source-route history, and record current MCP evidence. Proof: by-file metadata is `90/88`; change note records UID0000OH closeout, MCP database `supervisor_resume_20260629`, early positions, and zero-fill correction.
- [x] Insert no-standalone marker formal blocks into UID00006X, UID00006Y, UID0000CT, UID0000DM, UID0000DX, and UID0000ED. Proof: all six formal blocks contain the accepted no-standalone comments and `[[CHILDREN]]` insertion points required by generated output.
- [x] Insert UID0003J5 static `kWhichTargetPrompt` formal block, set score `88/92`, and set early emitter position before ItemWho constructor use. Proof: generated lines 18-19 define the prompt before ItemWho constructor line 57.
- [x] Insert UID0003J6 and UID0003J7 inline-literal marker formal blocks exactly as written. Proof: generated lines 580-581 and 1127-1128 emit marker comments only.
- [x] Insert UID0001LG and UID00036S class-scoped `ClearCurrentTarget` helper bodies and update scores. Proof: generated lines 545-552 and 1091-1098 emit both bodies.
- [x] Insert UID00048D covered-by marker to UID0001LD and update no-function/no-xref proof and score `88/89`. Proof: generated lines 554-555 emit the UID0001LD covered-by marker.
- [x] Insert UID0001LH and UID00036U `ForwardTabKey` bodies and document MapPane offset writes plus `GetTargetFilter()` first-draft accessor evidence/confidence cap. Proof: generated lines 557-578 and 1103-1124 emit both bodies; support docs record wrapper/accessor caveats.
- [x] Repair UID0001ND, UID0001NK, and UID0001NL metadata: `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++, score `89/91`, and scalar-wrapper no-source proof. Proof: generated UID counts for all three scalar wrappers are zero.
- [x] Insert UID0001LI constructor, UID0001LJ destructor, and UID0001LK key-handler formal bodies exactly as written; update scores where listed. Proof: generated lines 850-877 and 879 onward emit accepted TargetObject bodies.
- [x] Insert UID0001L9 and UID0001LA packet helper formal bodies, set early emitter positions, and preserve unsent scratch terminator/send-length proof. Proof: generated lines 21-48 emit both helpers with scratch terminators and fixed send lengths.
- [x] Insert UID0002AB and UID0002A2 static declaration formal blocks, set early emitter positions, update scores to `88/90`, and reject stale `0xffffffff` singleton initialization wording in favor of current zero-fill proof. Proof: generated lines 7-16 emit early statics; UID0002A2 and by-file text mark older `0xffffffff` wording stale.
- [x] Update Claim And Incorporation Ledger verification states from `proposed` to `applied`, `already-present`, or `excluded-with-reason` during callback. Proof: all ledger rows above are `applied` with destination proof.
- [x] Preserve negative evidence: raw UID00048D has no direct route, scalar destructors are compiler wrappers, prompt UID0003J6/UID0003J7 literals are already inline, dependency owners are rejected. Proof: corresponding support docs and by-file note retain no-route/compiler-wrapper/inline-literal/dependency-owner wording.
- [x] Run scoped validators for changed target/support docs. Proof: commands `000000001458`-`000000001482`, then class/generated correction commands `000000001485`-`000000001491`, all exit `0` with `ok:1` for file-mode scans.
- [x] Inspect regenerated `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`; confirm generated file freshness and that every accepted current empty marker is gone, emitted as exact code/marker, or absent due scalar metadata repair. Proof: generated file is 1,150 lines / 41,329 bytes, empty-marker count `0`, final by-file command `000000001491` reported `generated_refresh: completed`.
- [x] Release/expire all leases and report validator command ids plus any remaining blocker. Proof: `tools/leaser/lease.json` shows `"leases": {}`; no remaining blocker.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0000OH-TargetSelectionInputPanes-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0000OH-TargetSelectionInputPanes-empty-emitter-family-source-quality.md","timestamp":"2026-06-29T23:15:31","uid":"0000OH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
