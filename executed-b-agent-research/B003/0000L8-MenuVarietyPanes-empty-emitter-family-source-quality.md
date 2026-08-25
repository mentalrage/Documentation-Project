** TARGET-REPORT-UID:0000L8 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-STATUS:IMPLEMENTATION_CALLBACK_APPLIED_SUPERVISOR_VERIFICATION_REQUIRED **
** ASSIGNMENT:B003-implementation-callback-0000L8-MenuVarietyPanes-empty-emitter-family-20260629 **
** REPORT-DATE:2026-06-29 **

# UID0000L8 MenuVarietyPanes Empty Emitter Family Source-Quality Report

## Finalized Report / Current Recommendation
- Current recommendation: accept a coordinated implementation callback for all nine current empty emitters in `auto-generated/NexusTK/ui/menu/MenuVarietyPanes.cpp`.
- Final disposition: implementation callback applied. The class declarations, singleton globals, and menu hit-test helper now carry implementation-ready first-draft C++; vtable and exact storage children now carry marker-only C++ because those bytes are regenerated from class/global declarations.
- Required action: supervisor verification/execution only. Do not edit generated output by hand.
- Confidence: strong for ownership/source placement and implementation readiness; exact original symbol spellings remain a final-audit cap, not a report blocker.

## Target
- Target UID: [UID:0000L8].
- Target path: `by-file/MenuVarietyPanes.md`.
- Generated file: `auto-generated/NexusTK/ui/menu/MenuVarietyPanes.cpp`.
- Source queue/report row: Files With Empty Emitters, nine emitters, zero filled, nine empty.
- Current scores and parent state: file page currently records `COMPLETION:87`, `CONFIDENCE:86`, proposed path `NexusTK/ui/menu/`, and canonical file owner/emitter route for the menu-variety source family.

## Current Target State
- Existing metadata: `MenuVarietyPanes.md` owns the source file route for `MenuVarietyPane`, `MenuVarietySelectPane`, their singletons, their helper/body children, and menu resource labels.
- Existing C++/emitter state: the generated file is marker-only for all nine assigned emitters. It was last refreshed by validator command id `000000001133` at `2026-06-29T19:53:21-04:00`.
- Existing stale or incomplete assumptions: [UID:0002WF] still has stale header wording about `ff ff ff ff` initialization and older parent-gate uncertainty; current MCP proves zero initialization and the global parent route. [UID:0000RJ] also preserves an older `0xffffffff` initializer caveat; current MCP proves zero initialization for the active IDB.
- Related docs checked: `by-file/MenuVarietyPanes.md`, `by-class/MenuVarietyPane.md`, `by-class/MenuVarietySelectPane.md`, `by-global/g_pMenuVarietyPane.md`, `by-global/g_pMenuVarietySelectPane.md`, the five assigned by-memory pages, current generated `MenuVarietyPanes.cpp`, and `VoteMenuPane` generated/docs as local style precedent.

## Executive Recommendation
- Keep [UID:0000L8] `MenuVarietyPanes.md` as the source file route. This is a real menu UI source unit under `NexusTK/ui/menu/`, not a generic popup-control file, not `OldUserStatusPane`, and not `BulletinSession`.
- Populate [UID:000081] and [UID:000082] with declaration/prototype class shells and `[[CHILDREN]]` so exact method/helper children remain the body emitters.
- Populate [UID:0000RI] and [UID:0000RJ] with zero-initialized singleton definitions.
- Populate [UID:0001NQ] with the file-local ten-row hit-test helper body.
- Populate [UID:0002Z1], [UID:0002Z2], [UID:0002WF], and [UID:0002A4] with formal covered-by marker comments, not raw dword arrays or duplicate global definitions.
- No rare no-improvement exception applies. The current source gate permits first-draft C++ when `(COMPLETION + CONFIDENCE) / 2 > 85`, and all nine assigned emitters have enough same-pass evidence to resolve the empty marker state.

## Supervisor Active Recheck
- Supervisor instruction: new report-only assignment for [UID:0000L8] MenuVarietyPanes empty-emitter family; no leases; no by-* implementation edits; stop if MCP is unavailable.
- MCP status: active IDB session `3fa0535f` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` ok; Hex-Rays and strings cache ready.
- Split status: no new split is required for the nine assigned emitters. Adjacent helper/string pages are support context or already split.

## Inference Research Guidance Check
- `by-structure.md` requires current source-quality work to attempt owner, emitter, source placement, and C++ disposition in the same pass once scores clear the source gate. Historic "blank because final spellings are unresolved" is not enough for these scores.
- Direct IDA facts are separated below from documentation evidence and inference. Wave2/Wave3 historical references were treated as stale unless current docs and MCP evidence still supported them.
- Generated names such as `sub_5BD9B0`, `unk_69B4E8`, and `unk_69BF78` are not source names. The recommended source-facing names follow nearby accepted `VoteMenuPane` menu-popup style.

## Evidence Checked
- IDA MCP calls: `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `get_int`, `callees`, `decompile`, and `disasm` on the menu-variety constructor, selector constructor/destructor, click/mouse helpers, hit-test helper, vtables, and globals. Command ids used in this report: `201` through `214`; byte-read schema was corrected from stale `addr/size` to current `regions`.
- Function facts: `lookup_funcs` confirms modeled functions at `0x005bc610`, `0x005bc660`, `0x005bc690`, `0x005bc800`, `0x005bc880`, `0x005bc970`, `0x005bcf80`, `0x005bd000`, `0x005bd3a0`, `0x005bd3c0`, `0x005bd5b0`, `0x005bd9b0`, destructor thunks, scalar deleting destructors, and the vector append helper. `0x005bc890`, `0x005bd960`, `0x005bda3b`, and `0x005c0034` are not modeled functions.
- Bytes/ints: `get_bytes` and `get_int` prove `0x0069b4e8` and `0x0069bf78` are both `00 00 00 00` in the active IDB. Vtable slot dwords read as `0x005bfc80`, `0x005bfc0b`, `0x005bfc16`, `0x005bfce0`, `0x005bfc21`, and `0x005bfc2c`.
- Negative checks: `xrefs_to 0x005bd960` returns zero, so [UID:0001NQ] should not be drafted as a call to that helper. `0x005bd9b0` has only two code refs, both from `0x005bd000` selector mouse handling.
- Failed/unavailable checks: initial `get_bytes` calls with stale parameters returned "missing required parameters: ['regions']"; they were retried successfully with current schema. MCP remained available.

## Positive Evidence Summary
- The two classes are real `Pane` subclasses: constructors call `Pane::Pane(mode=1)`, publish singleton globals, write three vtable views each, and initialize menu-local state.
- [UID:000081] constructor at `0x005bc610` stores `g_pMenuVarietyPane`, clears byte `+0xf8`, and installs vtables at `0x00630d3c`, `0x00630d8c`, and `0x00630dbc`.
- [UID:000082] constructor at `0x005bc970` stores `g_pMenuVarietySelectPane`, clears bytes `+0xf8/+0xf9`, initializes vector triplet `+0xfc/+0x100/+0x104`, and appends labels `Userlook`, `Board`, `Mail`, `UserList`, `Friends`, `Target`, `Hotkey`, `Profile`, `Ranking`, and `Quit`.
- [UID:0001NQ] decompilation/disassembly show a ten-row loop, rectangles `(0, row * 16 + 6, 79, row * 16 + 22)`, `PointInRect`-style test, return row on hit, and return `-1` on miss.
- Local `VoteMenuPane` generated output provides accepted style: declaration-only class shell with row constants and helper prototypes, `g_pVoteMenuPane = NULL`, `Get...ItemRect`, and `HitTest...Item` file-local helpers.

## Negative Evidence Summary
- Raw vtable dword arrays are rejected as handwritten source. The vtable children are source-declared/generated-binary and are regenerated from class declarations, virtual method set, and compiler ABI.
- Raw storage children are rejected as duplicate globals. Source should define `g_pMenuVarietyPane` and `g_pMenuVarietySelectPane` once on the by-global pages; exact by-memory slots should carry covered-by markers.
- The stale `0xffffffff` singleton-initializer wording is rejected for current output. Active MCP reads both singleton slots as zero.
- `OldUserStatusPane` is rejected as owner because it is only a physical/read-only-data neighbor. `PopupMenuControls` is rejected as direct owner because the menu labels, `MENUVAR` art, and selector dispatch are feature-specific. `RankingDialog` and `QuitDialogs` are dispatch targets, not owners.
- The hit-test helper should remain file-local under `MenuVarietyPanes.cpp`, not a `BulletinSession` or generic rectangle helper. Its only callers are selector mouse-event sites.

## IDA MCP Facts
- Current session: `3fa0535f`, active, database path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `server_health` ok.
- Function inventory: `sub_5BD9B0` is `0x005bd9b0-0x005bda3b`, 0x8b bytes, returns by `retn 8`, and calls `sub_4B7C50`, `sub_4B7E80`, and stack-cookie check.
- Selector mouse handler `0x005bd000` calls `0x005bd9b0` at `0x005bd089` for release dispatch and at `0x005bd338` for hover tracking.
- Global xrefs: `0x0069b4e8` has nine refs, including `0x005bc635`, `0x005bc67a`, selector dismissal paths, notify/delete helper, and scalar deleting destructor. `0x0069bf78` has seven refs, including menu button click/draw, selector ctor/dtor, clear helper, and scalar deleting destructor.
- Vtable xrefs: MenuVarietyPane vtable bases `0x00630d3c`, `0x00630d8c`, `0x00630dbc` each have constructor/destructor/scalar-destructor refs. MenuVarietySelectPane bases `0x00630dc8`, `0x00630e1c`, `0x00630e4c` have the same pattern.

## Function / Child Inventory
| Item | UID / Path | Role | Current status | Report disposition |
| --- | --- | --- | --- | --- |
| MenuVarietyPane | [UID:000081] `by-class/MenuVarietyPane.md` | Button pane class declaration/prototype layer | `86/88`, empty formal block | Declaration-only C++ with `[[CHILDREN]]`; recommend `87/90` |
| MenuVarietyPane vtables | [UID:0002Z1] `by-memory/0x00630d3c-0x00630dc8.MenuVarietyPaneVtableData.md` | compiler-generated vtable data | `87/92`, empty formal block | Covered-by marker through [UID:000081]; recommend `88/92` |
| MenuVarietySelectPane | [UID:000082] `by-class/MenuVarietySelectPane.md` | Selector class declaration/prototype layer | `86/88`, empty formal block | Declaration-only C++ with `[[CHILDREN]]`; recommend `87/90` |
| MenuVarietySelectPane vtables | [UID:0002Z2] `by-memory/0x00630dc8-0x00630e58.MenuVarietySelectPaneVtableData.md` | compiler-generated vtable data | `87/92`, empty formal block | Covered-by marker through [UID:000082]; recommend `88/92` |
| g_pMenuVarietyPane | [UID:0000RI] `by-global/g_pMenuVarietyPane.md` | active singleton global | `86/90`, empty formal block | `MenuVarietyPane *g_pMenuVarietyPane = NULL;`; recommend `87/91` |
| exact g_pMenuVarietyPane slot | [UID:0002WF] `by-memory/0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane.md` | exact storage child | `88/93`, empty formal block with stale summary | Covered-by marker and stale zero-init correction; recommend `89/93` |
| g_pMenuVarietySelectPane | [UID:0000RJ] `by-global/g_pMenuVarietySelectPane.md` | active selector singleton global | `86/88`, empty formal block | `MenuVarietySelectPane *g_pMenuVarietySelectPane = NULL;`; recommend `87/90` |
| exact selector singleton slot | [UID:0002A4] `by-memory/0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton.md` | exact storage child | `91/90`, empty formal block with stale initializer caveat | Covered-by marker and zero-init correction; recommend `92/91` |
| selector hit-test | [UID:0001NQ] `by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md` | file-local source helper | `86/90`, empty formal block | First-draft helper body; recommend `87/91` |

## Ranked Ownership Analysis

### 1. [UID:0000L8] MenuVarietyPanes.cpp
- Evidence for: source-tree placement, file page contents, menu art/labels, two classes, two singletons, and selector dispatch form one feature source file. Both class pages already point to this file route.
- Evidence against: exact class method bodies remain on by-memory children; this is normal for current reconstruction output and does not weaken file ownership.
- Decision: best source file route for all nine assigned emitters.

### 2. Direct class pages [UID:000081] and [UID:000082]
- Evidence for: class constructors, vtables, destructors, fields, and exact method inventories are class-specific. Class pages clear the source gate and should emit declarations before child bodies.
- Evidence against: globals and file-local static hit-test are not class member bodies.
- Decision: class pages should emit declaration/prototype shells; their vtable children are marker-only coverage through those declarations.

### 3. Direct global pages [UID:0000RI] and [UID:0000RJ]
- Evidence for: each global page names the source global; active MCP proves zero-initialized 4-byte storage and lifecycle refs.
- Evidence against: exact storage pages are not separate source definitions.
- Decision: globals emit definitions; by-memory storage children emit covered-by markers.

### Rejected owners
- `OldUserStatusPane`: physical successor/neighbor only.
- `PopupMenuControls`: reusable style/framework only, not owner of feature-specific labels and dispatch.
- `RankingDialog`, `QuitDialogs`, and other opened panes: downstream dispatch targets only.
- `BulletinSession`: no relevant ownership evidence for this menu selector hit-test.

## Source Placement
- Recommended source file/class/global placement: `NexusTK/ui/menu/MenuVarietyPanes.cpp`.
- Class pages: `MenuVarietyPane` and `MenuVarietySelectPane` declaration/prototype blocks with `[[CHILDREN]]`.
- Globals: `g_pMenuVarietyPane` and `g_pMenuVarietySelectPane` definitions in the same generated source file after class/body coverage, matching `VoteMenuPane`.
- Helper: `HitTestMenuVarietyItem` as a `static` file-local helper in `MenuVarietyPanes.cpp`.

## First-Draft C++ Recommendation

Eligible for draft C++: [UID:000081], [UID:000082], [UID:0000RI], [UID:0000RJ], and [UID:0001NQ]. Eligible for marker-only formal C++: [UID:0002Z1], [UID:0002Z2], [UID:0002WF], and [UID:0002A4].

### [UID:000081] MenuVarietyPane formal block
Use this exact insertion text between the target `RECONSTRUCTION_CPP CODE:BEGIN` and `END` markers:

```cpp
struct PaneMouseEvent;
struct Rect;
class MenuVarietySelectPane;

class MenuVarietyPane : public Pane
{
public:
    MenuVarietyPane();
    virtual ~MenuVarietyPane();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual void OnPaint();
    virtual int RefreshMenuButton();

private:
    unsigned char m_menuButtonPressed;    // +0xf8
};

extern MenuVarietyPane *g_pMenuVarietyPane;
extern MenuVarietySelectPane *g_pMenuVarietySelectPane;

static void GetMenuVarietyButtonRect(int row, Rect *rect);

[[CHILDREN]]
```

### [UID:000082] MenuVarietySelectPane formal block
Use this exact insertion text between the target `RECONSTRUCTION_CPP CODE:BEGIN` and `END` markers:

```cpp
struct PaneMouseEvent;
struct PaneEvent;
struct Rect;
class SimpleUString;

class MenuVarietySelectPane : public Pane
{
public:
    MenuVarietySelectPane();
    virtual ~MenuVarietySelectPane();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual bool OnDismiss(const PaneEvent *event);
    virtual void OnPaint();
    virtual void DrawBackground();
    virtual void DrawBorder();

private:
    enum {
        kUserlookRow = 0,
        kBoardRow = 1,
        kMailRow = 2,
        kUserListRow = 3,
        kFriendsRow = 4,
        kTargetRow = 5,
        kHotkeyRow = 6,
        kProfileRow = 7,
        kRankingRow = 8,
        kQuitRow = 9,
        kMenuRowCount = 10,
        kNoMenuRow = -1
    };

    unsigned char m_menuRowPressed;       // +0xf8
    signed char m_highlightedMenuRow;     // +0xf9
    unsigned char m_reservedFA[2];        // +0xfa..+0xfb alignment
    SimpleUString *m_menuLabelsBegin;     // +0xfc
    SimpleUString *m_menuLabelsEnd;       // +0x100
    SimpleUString *m_menuLabelsCapacity;  // +0x104
};

extern MenuVarietySelectPane *g_pMenuVarietySelectPane;

static void GetMenuVarietyItemRect(int row, Rect *rect);
static int HitTestMenuVarietyItem(int x, int y);

[[CHILDREN]]
```

### [UID:0000RI] g_pMenuVarietyPane formal block

```cpp
MenuVarietyPane *g_pMenuVarietyPane = NULL;
```

### [UID:0000RJ] g_pMenuVarietySelectPane formal block

```cpp
MenuVarietySelectPane *g_pMenuVarietySelectPane = NULL;
```

### [UID:0001NQ] MenuVarietySelectPaneHitTest formal block

```cpp
static int HitTestMenuVarietyItem(int x, int y)
{
    Rect rect;

    for (int row = 0; row < 10; ++row) {
        SetRect(&rect, 0, row * 16 + 6, 79, row * 16 + 22);
        if (PointInRect(rect, x, y))
            return row;
    }

    return -1;
}
```

### Marker-only formal blocks
Use one-line formal markers rather than blank empty-emitter output:

```cpp
// Emitted code for this MenuVarietyPane vtable-data range is covered by [UID:000081] MenuVarietyPane class declarations.
```

```cpp
// Emitted code for this MenuVarietySelectPane vtable-data range is covered by [UID:000082] MenuVarietySelectPane class declarations.
```

```cpp
// Emitted storage for g_pMenuVarietyPane is covered by [UID:0000RI] g_pMenuVarietyPane.
```

```cpp
// Emitted storage for g_pMenuVarietySelectPane is covered by [UID:0000RJ] g_pMenuVarietySelectPane.
```

Reason the code preserves behavior: the class shells regenerate vtables; global definitions match zero-initialized active bytes and lifecycle refs; hit-test matches the decompiled and disassembled ten-row rectangle loop. Reason not higher: exact original method names, exact string typedef name, and final helper naming remain inferred from local style and binary behavior.

## Recommended Target Doc Changes
- `by-file/MenuVarietyPanes.md`: add this report as a 2026-06-29 B003 empty-emitter family source-quality pass; record that the nine empty emitters are implementation-ready and no no-improvement exception applies.
- Add a source split table matching the nine assigned emitters: class declaration pages, global definition pages, marker-only vtable/storage pages, and hit-test helper body.
- Preserve rejected alternatives: `OldUserStatusPane`, `PopupMenuControls`, downstream dialog owners, and `BulletinSession`.

## Recommended Support Doc Changes
- `by-class/MenuVarietyPane.md`: insert the formal declaration/prototype block, set `EMITTER_POSITION_OPTIONAL:0`, mention the `+0xf8` pressed byte, and raise to `87/90`.
- `by-class/MenuVarietySelectPane.md`: insert the formal declaration/prototype block, set `EMITTER_POSITION_OPTIONAL:0`, mention `+0xf8/+0xf9` and vector triplet `+0xfc/+0x100/+0x104`, and raise to `87/90`.
- `by-global/g_pMenuVarietyPane.md`: insert the singleton definition, record current MCP zero bytes and xrefs, and raise to `87/91`.
- `by-global/g_pMenuVarietySelectPane.md`: insert the singleton definition, remove/historicalize the stale `0xffffffff` initializer caveat, record current MCP zero bytes and xrefs, and raise to `87/90`.
- `by-memory/0x00630d3c-0x00630dc8.MenuVarietyPaneVtableData.md`: insert marker-only formal block, preserve vtable slot/xref facts, raise to `88/92`.
- `by-memory/0x00630dc8-0x00630e58.MenuVarietySelectPaneVtableData.md`: insert marker-only formal block, preserve vtable slot/xref facts, raise to `88/92`.
- `by-memory/0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane.md`: insert marker-only formal block, correct stale Item Summary/current bytes to zero-initialized, raise to `89/93`.
- `by-memory/0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton.md`: insert marker-only formal block, correct stale initializer caveat to current zero-initialized MCP evidence, raise to `92/91`.
- `by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md`: insert the formal helper body, record the two caller refs from `0x005bd000`, zero xrefs to `0x005bd960`, row constants, and raise to `87/91`.
- Already-present or excluded support docs: resource/label string pages such as `by-memory/0x00630f8c-0x0063104c.MenuVarietyResourceAndLabelStrings.md` and neighboring helper pages [UID:0003AH], [UID:0003AI], and [UID:0003AJ] are support context only for this report. Do not edit them unless the supervisor's implementation callback explicitly expands scope.

## Score And Metadata Recommendation
| UID | Current | Recommended | Metadata/C++ disposition |
| --- | --- | --- | --- |
| 0000L8 | `87/86` | no mandatory score change | source file summary should record the empty-emitter repair route |
| 000081 | `86/88` | `87/90` | `EMITTER_POSITION_OPTIONAL:0`, declaration block with `[[CHILDREN]]` |
| 0002Z1 | `87/92` | `88/92` | marker-only vtable coverage through [UID:000081] |
| 000082 | `86/88` | `87/90` | `EMITTER_POSITION_OPTIONAL:0`, declaration block with `[[CHILDREN]]` |
| 0002Z2 | `87/92` | `88/92` | marker-only vtable coverage through [UID:000082] |
| 0000RI | `86/90` | `87/91` | zero-initialized singleton definition |
| 0002WF | `88/93` | `89/93` | marker-only storage coverage; stale initializer/parent wording corrected |
| 0000RJ | `86/88` | `87/90` | zero-initialized singleton definition |
| 0002A4 | `91/90` | `92/91` | marker-only storage coverage; stale initializer wording corrected |
| 0001NQ | `86/90` | `87/91` | first-draft hit-test helper body |

Score-improvement attempt: constants, scratch declarations, sibling style, storage declarations, and generated marker-only output were investigated in this pass. None are accepted blockers under the current score standard. Remaining caps are original symbol spelling, final public string/vector facade naming, and exact whole-file body completeness, not implementation blockers for the assigned empty emitters.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | [UID:0000L8] remains the source file route for the nine emitters. | Strong | file docs, generated source route, class/global refs | `by-file/MenuVarietyPanes.md` Source Split/Changes | incorporated report summary/source split and rejected owners | applied; validator `000000001182` exit 0, `ok: 1` |
| C02 | [UID:000081] can emit declaration/prototype C++ with `[[CHILDREN]]`. | Strong | ctor decompile, vtable refs, VoteMenuPane style | `by-class/MenuVarietyPane.md` formal C++/Source Reconstruction Policy | inserted exact block, score `87/90`, `EMITTER_POSITION_OPTIONAL:0` | applied; validator `000000001184` exit 0, `ok: 1` |
| C03 | [UID:000082] can emit declaration/prototype C++ with `[[CHILDREN]]`. | Strong | ctor/dtor/mouse decompile, fields, labels, VoteMenuPane style | `by-class/MenuVarietySelectPane.md` formal C++/Layout Notes | inserted exact block, score `87/90`, `EMITTER_POSITION_OPTIONAL:0` | applied; validator `000000001186` exit 0, `ok: 1` |
| C04 | MenuVarietyPane vtable bytes are compiler-generated class data. | Strong | slot dwords, constructor/destructor/scalar refs | `by-memory/0x00630d3c-0x00630dc8.MenuVarietyPaneVtableData.md` C++/Evidence | inserted marker-only block and score `88/92` | applied; validator `000000001193` exit 0, `ok: 1` |
| C05 | MenuVarietySelectPane vtable bytes are compiler-generated class data. | Strong | slot dwords, constructor/destructor/scalar refs | `by-memory/0x00630dc8-0x00630e58.MenuVarietySelectPaneVtableData.md` C++/Evidence | inserted marker-only block and score `88/92` | applied; validator `000000001195` exit 0, `ok: 1` |
| C06 | `g_pMenuVarietyPane` is a zero-initialized singleton definition. | Strong | `get_bytes/get_int 0x0069b4e8`, nine xrefs | `by-global/g_pMenuVarietyPane.md` formal C++/Evidence | inserted definition and score `87/91` | applied; validator `000000001188` exit 0, `ok: 1` |
| C07 | `0x0069b4e8` exact storage should not duplicate the global definition. | Strong | zero bytes, direct global page, storage-child role | `by-memory/0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane.md` formal C++/Item Summary | inserted marker-only block, stale summary correction, score `89/93` | applied; validator `000000001197` exit 0, `ok: 1` |
| C08 | `g_pMenuVarietySelectPane` is a zero-initialized singleton definition. | Strong | `get_bytes/get_int 0x0069bf78`, seven xrefs | `by-global/g_pMenuVarietySelectPane.md` formal C++/Evidence | inserted definition, historicalized stale caveat, score `87/90` | applied; validator `000000001190` exit 0, `ok: 1` |
| C09 | `0x0069bf78` exact storage should not duplicate the global definition. | Strong | zero bytes, direct global page, storage-child role | `by-memory/0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton.md` formal C++/Evidence | inserted marker-only block, stale summary correction, score `92/91` | applied; validator `000000001199` exit 0, `ok: 1` |
| C10 | [UID:0001NQ] can emit `static int HitTestMenuVarietyItem(int x, int y)`. | Strong | decompile/disasm, two selector callers, no `0x005bd960` xrefs | `by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md` formal C++/Evidence | inserted exact helper body, caller/xref notes, score `87/91` | applied; validator `000000001200` exit 0, `ok: 1` |
| C11 | `VoteMenuPane` supplies local source-style precedent only. | Medium | generated `VoteMenuPane.cpp` and docs | all target/support doc implementation notes | cited as style evidence, not ownership | applied across target/class/hit-test support docs; validator batch exit 0 |
| C12 | Resource string and sibling helper pages are support context only for this callback. | Strong | assignment lists only nine empty emitters and supervisor bounded scope | implementation checklist/exclusions | left unedited; warnings for `0003AH/0003AI/0003AJ/0003JD` are validator registry gaps, not callback scope | excluded-with-reason |

## Open Questions With Attempted Resolution
- Exact original method spellings: checked class docs, generated output, local `VoteMenuPane` style, and MCP decompilation. Best current source-facing names are descriptive and consistent; unresolved original spellings cap confidence but do not block first-draft C++.
- Exact wide-string/vector facade name: checked constructor field layout and project docs. `SimpleUString *begin/end/capacity` pointer-triplet declaration is safer than inventing a complete `std::vector` typedef; unresolved facade name caps class confidence.
- Hit-test helper return type: binary returns an 8-bit value, but sibling source style uses `int` for hit-test helpers and callers switch/store values safely. Use `int` as source-facing first draft.
- Singleton initializer: resolved by current MCP as zero for both globals. The stale `0xffffffff` wording should be historicalized or removed during implementation.

## Validator Results
- Implementation callback validators were run in a scoped batch; full tee log: `tools/leaser/Agents/Agent-B003/0000L8-validator-rerun.log`.
- `by-file/MenuVarietyPanes.md`: command id `000000001182`, timestamp `2026-06-29T20:23:37-04:00`, exit `0`, `ok: 1`.
- `by-class/MenuVarietyPane.md`: command id `000000001184`, timestamp `2026-06-29T20:23:57-04:00`, exit `0`, `ok: 1`.
- `by-class/MenuVarietySelectPane.md`: command id `000000001186`, timestamp `2026-06-29T20:24:19-04:00`, exit `0`, `ok: 1`.
- `by-global/g_pMenuVarietyPane.md`: command id `000000001188`, timestamp `2026-06-29T20:24:37-04:00`, exit `0`, `ok: 1`.
- `by-global/g_pMenuVarietySelectPane.md`: command id `000000001190`, timestamp `2026-06-29T20:24:57-04:00`, exit `0`, `ok: 1`.
- `by-memory/0x00630d3c-0x00630dc8.MenuVarietyPaneVtableData.md`: command id `000000001193`, timestamp `2026-06-29T20:25:16-04:00`, exit `0`, `ok: 1`.
- `by-memory/0x00630dc8-0x00630e58.MenuVarietySelectPaneVtableData.md`: command id `000000001195`, timestamp `2026-06-29T20:25:36-04:00`, exit `0`, `ok: 1`.
- `by-memory/0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane.md`: command id `000000001197`, timestamp `2026-06-29T20:25:57-04:00`, exit `0`, `ok: 1`.
- `by-memory/0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton.md`: command id `000000001199`, timestamp `2026-06-29T20:26:16-04:00`, exit `0`, `ok: 1`.
- `by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md`: command id `000000001200`, timestamp `2026-06-29T20:26:36-04:00`, exit `0`, `ok: 1`.
- Validator-owned generated refreshes completed for each scoped command. Current generated freshness checked after lease release: `auto-generated/NexusTK/ui/menu/MenuVarietyPanes.cpp` header records validator command id `000000001210`, refreshed `2026-06-29T20:28:39-04:00`, and contains no `Empty Emitter Marker` line for the accepted callback UIDs. The generated file includes [UID:000081], [UID:0002Z1], [UID:000082], [UID:0002Z2], [UID:0000RI], [UID:0000RJ], and [UID:0001NQ]; [UID:0002WF] and [UID:0002A4] remain covered by the emitted global definitions and have no separate empty-marker output.
- Known validator warnings: `missing_ref_uid` references for support-only UIDs `0003AH`, `0003AI`, `0003AJ`, and `0003JD` appear where existing docs cite unregistered support rows. These are intentionally excluded from this bounded callback and did not prevent `ok: 1` / exit `0` for the scoped targets.

## Changed Files
- Modified by implementation callback: `by-file/MenuVarietyPanes.md`, `by-class/MenuVarietyPane.md`, `by-class/MenuVarietySelectPane.md`, `by-global/g_pMenuVarietyPane.md`, `by-global/g_pMenuVarietySelectPane.md`, `by-memory/0x00630d3c-0x00630dc8.MenuVarietyPaneVtableData.md`, `by-memory/0x00630dc8-0x00630e58.MenuVarietySelectPaneVtableData.md`, `by-memory/0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane.md`, `by-memory/0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton.md`, and `by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md`.
- Updated proof/report artifacts: `tools/leaser/Agents/Agent-B003/research/0000L8-MenuVarietyPanes-empty-emitter-family-source-quality.md` and `tools/leaser/Agents/Agent-B003/0000L8-validator-rerun.log`.
- Validator-owned generated freshness output: `auto-generated/NexusTK/ui/menu/MenuVarietyPanes.cpp` was refreshed by the validator, not edited by hand.
- Report execution: not run; supervisor owns execute/move/archive/register.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update listed: `by-file/MenuVarietyPanes.md`, `by-class/MenuVarietyPane.md`, `by-class/MenuVarietySelectPane.md`, `by-global/g_pMenuVarietyPane.md`, `by-global/g_pMenuVarietySelectPane.md`, and the five assigned by-memory pages.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply listed.
- [x] Score-limiting blockers researched to resolution; no rare no-improvement proof needed.
- [x] Owner/emitter/reconstructable changes to apply: keep current source owner routes; add formal C++/marker output as listed.
- [x] Split/rename/new-child changes to apply: none.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable.
- [x] First-draft C++ and marker-only no-code proof supplied.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail supplied.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve listed.
- [x] Wave2/Wave3 mentions treated as stale unless current evidence supports them.
- [x] Open questions closed or documented as evidence-backed unresolved.
- [x] Validators to run during callback listed.
- [x] Generated report refresh expected; no manual supervisor-owned coverage text supplied.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] Took short leases only while editing target/support docs; released all ten leased docs successfully after edit/validator batch.
- [x] Applied target doc changes to `by-file/MenuVarietyPanes.md`.
- [x] Applied class declaration blocks, metadata, source-policy notes, and scores to `by-class/MenuVarietyPane.md` and `by-class/MenuVarietySelectPane.md`.
- [x] Applied singleton global definitions, zero-init evidence, stale wording cleanup, and scores to `by-global/g_pMenuVarietyPane.md` and `by-global/g_pMenuVarietySelectPane.md`.
- [x] Applied marker-only vtable blocks and scores to `by-memory/0x00630d3c-0x00630dc8.MenuVarietyPaneVtableData.md` and `by-memory/0x00630dc8-0x00630e58.MenuVarietySelectPaneVtableData.md`.
- [x] Applied marker-only storage blocks, zero-init corrections, and scores to `by-memory/0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane.md` and `by-memory/0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton.md`.
- [x] Applied hit-test helper body, caller/xref evidence, negative `0x005bd960` xref evidence, and score to `by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md`.
- [x] Left generated C++, manual coverage reports, validator/tool state, IDA DB, executed archives, and supervisor ledgers untouched by hand.
- [x] Left resource string and sibling helper support docs unedited because callback did not expand scope; validator registry warnings for `0003AH/0003AI/0003AJ/0003JD` are intentionally excluded.
- [x] Ran scoped validators and recorded command ids/timestamps/results.
- [x] Confirmed generated `MenuVarietyPanes.cpp` freshness and accepted empty markers resolved by validator refresh.
- [x] Updated this report ledger/checklist with implementation proof after supervisor callback acceptance.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0000L8-MenuVarietyPanes-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0000L8-MenuVarietyPanes-empty-emitter-family-source-quality.md","timestamp":"2026-06-29T20:57:24","uid":"0000L8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
