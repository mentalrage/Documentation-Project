** TARGET-REPORT-UID:0000FX **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000FX VoteMenuPane Class Source-Quality Report

Status: FINISHED

Agent: B014

Target: [UID:0000FX] `by-class/VoteMenuPane.md`

Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/0000FX-VoteMenuPane-class-source-quality.md`

Scope: report-only Rule 26 source-quality pass. I did not edit `by-class`, `by-file`, `by-type`, `by-global`, `by-memory`, or `by-memory/-coverage-report.md`.

## Executive Recommendation

Raise [UID:0000FX] `VoteMenuPane` from `86/85` to `88/90`, keep `CANONICAL_OWNER:0000P6`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000P6`, and populate declaration-level first-draft C++ on the class page. The class now clears the active current gate because it is reconstructable, has a valid file emitter, and `(88 + 90) / 2 > 85`.

The class C++ should be declaration-only with helper prototypes, the singleton declaration, resolved tail fields, row constants, and `[[CHILDREN]]` placed after the class declaration so exact by-memory method/helper definitions emit outside the class body. The current autogen ordering leaves the class as an empty marker after method bodies, so the callback should also set `EMITTER_POSITION_OPTIONAL:0` on the class page or make an equivalent validator-supported ordering change that places the class declaration/prototypes before child method bodies.

The class-level report should not pull method bodies into the class page. The exact source bodies remain on the method children. The scalar deleting destructor and two adjustor thunks remain compiler-generated no-code support. The raw constructor [UID:0002LQ] is now first-draft C++ ready if the supervisor accepts this class-shell update: the old constructor hold depended partly on missing accepted field declarations, and this pass resolves the class declaration, field names, and constructor source shape well enough to emit a source-authored constructor body while preserving the no-direct-caller cap.

## Evidence Checked

- Required process docs:
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - `.codex/AGENTS.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B014/goal.md`, including the Implementation Callback Detail Contract
  - `source-3/project-documentation/by-structure.md`
  - `source-3/project-documentation/inference_research.md`
  - `source-3/project-documentation/by-class/-guidance.md`
- Target and support docs:
  - `by-class/VoteMenuPane.md`
  - `by-file/VoteMenuPane.md`
  - `by-type/by-struct/VoteMenuPaneLayout.md`
  - `by-type/by-vtable/VoteMenuPaneVtables.md`
  - `by-global/g_pVoteMenuPane.md`
  - `by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md`
  - `by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md`
  - `by-memory/0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit.md`
  - exact child docs `0002LQ` through `0002LZ`, destructor thunks, scalar deleting destructor, vtable data, and command strings
  - comparison docs for `RightButtonMenuPane`, `ChattingVarietyPane`, `ChattingVarietySelectPane`, `DirectX`, `RankingCategoryRecord`, `SelectBoxControlPane`, `TotemFrame`, and `WebBoardDialog`
- Prior accepted/executed B reports:
  - `Agent-B001/research/executed/0002LQ-votemenupane-raw-constructor-source-quality.md`
  - `Agent-B003/research/executed/0002LR-0002LS-0002LT-0002LU-0002LV-0002LW-0002LX-0002LY-0002LZ-0001G3-votemenupane-source-quality.md`
- Generated output:
  - `auto-generated/NexusTK/ui/menu/VoteMenuPane.cpp`
- Direct local binary recheck:
  - PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - MD5: `4247e04e20b65d6414c7238aa8ff5515`
  - SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
  - Image base: `0x00400000`
- Live IDA/MCP availability:
  - Attempted `http://127.0.0.1:13337/mcp`; no server was reachable in this session. The report therefore relies on accepted IDA-backed documentation plus direct PE/Capstone checks.

## Direct Binary Recheck Facts

- Raw constructor `0x005558d0-0x00555945`:
  - no rel32 call/jump refs to `0x005558d0`
  - no absolute VA dword hits for `0x005558d0`
  - constructor-shaped `thiscall` body with `ret 8`
  - calls `0x00544460` with argument `1`, matching the B001 conclusion `Pane::Pane(mode=1)` rather than a visible flag
  - writes `g_pVoteMenuPane` at `0x0069ba38`
  - clears `this+0xf8`
  - stores first constructor argument at `this+0xfc`
  - copies second constructor argument into `this+0x100` using `wcscpy_s` count `0x21`
  - installs VoteMenuPane vtables based at `0x00622ff8`, `0x0062304c`, and `0x0062307c`
  - sets `this+0xf9` to `0xff`, the signed `-1` highlighted-row sentinel
  - exact trailing padding is `0x00555945-0x00555950` `int3` fill
- Vtable base immediates:
  - `0x00622ff8` stores at `0x00555915`, `0x00555977`, `0x0055634e`
  - `0x0062304c` stores at `0x0055591f`, `0x00555981`, `0x00556358`
  - `0x0062307c` stores at `0x00555929`, `0x0055598b`, `0x00556362`
  - These stores are constructor, ordinary destructor, and scalar deleting destructor lifecycle evidence, not independent caller evidence for the raw constructor.
- Method/helper routes:
  - `GetVoteMenuItemRect` at `0x00556020` has direct caller `0x00555b9f` from `OnPaint`.
  - `HitTestVoteMenuItem` at `0x00556070` has direct callers `0x00555a0d` and `0x00555aa8` from `OnMouseEvent`.
  - `SubmitVote` at `0x00556100` has direct caller `0x00555a32` from `OnMouseEvent`.
  - `RightButtonMenuPane::CloseRightClickAndVoteMenus` at `0x005552a0` is called from `0x00555a3d` immediately after submit handling.
  - `Pane::MarkForDeletion` at `0x00544690` is the shared dismissal helper reached by the mouse miss/down path and `OnDismiss`.
- Destructor glue:
  - `0x00556228` subtracts `0xa0` from `ecx` and jumps to scalar deleting destructor `0x00556320`.
  - `0x00556233` subtracts `0xa4` from `ecx` and jumps to scalar deleting destructor `0x00556320`.
  - `0x00556320` is compiler-generated scalar deleting destructor glue that restores vptrs, calls the same cleanup helpers and `Pane` teardown path, clears `g_pVoteMenuPane`, and conditionally frees memory by delete flag. It should stay no-code.
- Data and strings:
  - `g_pVoteMenuPane` at `0x0069ba38` is zero-initialized in `.data`.
  - `0x006230a8` decodes as UTF-16 `Promote`.
  - `0x006230b8` decodes as UTF-16 `Demote`.
  - `0x00610b74` decodes as `SUBWIN.EPF`.
  - `0x00610b8c` decodes as `SUBWIN.PAL`.

## Source-Quality Decisions

| Issue | Resolution | Evidence and rejected alternatives |
| --- | --- | --- |
| Source file route | Keep source root [UID:0000P6] `VoteMenuPane` / generated `NexusTK/ui/menu/VoteMenuPane.cpp`. | All child bodies are VoteMenuPane popup behavior, the file page already owns the source island, and RightButtonMenuPane only closes the popup after a vote. Reject old `BulletinSession` helper ownership and CashShop/inbound packet placement as caller pollution. |
| Class-level C++ | Emit declaration-level class shell now. | Current gate is satisfied. Exact method/helper bodies already emit from children; class page is the missing declaration/prototype layer needed by the file draft. |
| `[[CHILDREN]]` placement | Put `[[CHILDREN]]` after the class declaration, not inside the class. | Child pages emit out-of-class definitions like `VoteMenuPane::OnMouseEvent`; inside-class insertion would be source-invalid. `RankingCategoryRecord`, `SelectBoxControlPane`, `TotemFrame`, and `WebBoardDialog` use the after-class pattern for this reason. |
| Emitter ordering | Set `EMITTER_POSITION_OPTIONAL:0` on [UID:0000FX], or otherwise ensure the declaration/prototypes precede method bodies. | Current generated `VoteMenuPane.cpp` emits method bodies first and then an empty class marker. The class shell must come before those bodies. |
| Constructor signature | `VoteMenuPane::VoteMenuPane(int voteType, const wchar_t *targetName)`. | Raw body has `ret 8`, first argument stored at `+0xfc`, second argument copied to `m_targetName[0x21]`. No caller route narrows the first argument beyond `voteType`/context, so keep it broad. |
| Constructor first-draft C++ | Recommended ready in child [UID:0002LQ] if supervisor accepts this class report. | B001 left C++ blank partly pending accepted field declarations; this report resolves the class fields and source shell. No direct constructor caller still caps score, but does not block source-authored constructor C++ for a complete constructor body. |
| Ordinary destructor | Keep [UID:0002LR] first-draft `VoteMenuPane::~VoteMenuPane()` body on the child page. | It is source-authored cleanup. Vptr restores remain compiler-emitted and should not be written manually. |
| Scalar deleting destructor | Keep [UID:0001G3] no-code. | It is compiler-generated wrapper glue selected by delete flags and secondary-base adjustor thunks. Source destructor is already represented by [UID:0002LR]. |
| Adjustor thunks | Keep `0x00556228` and `0x00556233` no-code/generated-binary support. | They only adjust `ecx` by secondary-base offsets and jump to scalar deleting destructor. They prove secondary vtable layout only. |
| `m_voteRowPressed` | Field at `+0xf8`, `unsigned char` or `bool` storage. | Constructor clears it; mouse down sets true; release tests and clears it. Use `unsigned char` in class layout to match byte storage while child C++ may use boolean semantics. |
| `m_highlightedVoteRow` | Field at `+0xf9`, signed byte. | Constructor and release use `-1`; hover stores hit-test return row; paint tests row `0` or `1`. |
| padding | `+0xfa..+0xfb` alignment padding. | Next dword field is aligned at `+0xfc`; no observed field behavior in the two bytes. |
| `m_voteType` | Field at `+0xfc`, constructor context, not the Promote/Demote packet flag. | Constructor stores first argument; no child body reads it in the recovered island. Packet flags derive from clicked row: row `0` sends `1`, row `1` sends `0`. Keep name broad and document unresolved caller-side semantics. |
| `m_targetName` | `wchar_t m_targetName[0x21]` at `+0x100`. | Constructor copies with `wcscpy_s(..., 0x21, targetName)`; submit converts it to ANSI and skips empty target names. |
| Row constants | `kPromoteRow = 0`, `kDemoteRow = 1`, `kNoVoteRow = -1`. | Hit-test loops row `0..1`; row rectangles and packet flags match these semantics. |
| Row rectangles | Promote `(0, 6, 79, 22)`, Demote `(0, 22, 79, 38)`, sentinel `(-1,-1,-1,-1)`. | `GetVoteMenuItemRect` computes `top = row * 16 + 6`, `bottom = row * 16 + 22`, `right = 79`, with special `-1` sentinel. |
| Mouse event names | `OnMouseEvent(const PaneMouseEvent *event)`, event kind `0` hover, `1` button-down/capture, `3` button-up/release. | Child [UID:0002LS] already emits this first draft. This is the best source-facing naming; exact framework enum names remain unknown but behavior is resolved. |
| Paint/background/border names | Keep `OnPaint`, `DrawBackground`, `DrawBorder`. | Vtable slot context and method bodies support these class virtual names; SUBWIN resource use supports background/border split. |
| Helper names | Keep file-local `GetVoteMenuItemRect`, `HitTestVoteMenuItem`, `SubmitVote`. | Source-facing names are behavior-derived and caller-derived. Exact original spellings remain unrecovered, but the owner/file-local placement is now strong. |
| Packet semantics | `SubmitVote` sends outbound opcode `0x46`, submode byte `0`, target byte length, target ANSI bytes, and vote flag. | The only caller is `OnMouseEvent`; row `0` passes `1` for Promote, row `1` passes `0` for Demote. Reject inbound packet handler and CashShop interpretations. |
| Singleton | `VoteMenuPane *g_pVoteMenuPane = NULL` should be represented in the VoteMenuPane source file by the global support page. | Constructor publishes `this`; ordinary destructor and scalar deleting destructor clear it; RightButtonMenuPane references the singleton to close menus. |

## First-Draft Class C++ Recommendation

Recommended exact class-page `RECONSTRUCTION_CPP CODE` block for [UID:0000FX]:

```cpp
struct PaneMouseEvent;
struct PaneEvent;
struct Rect;

class VoteMenuPane : public Pane
{
public:
    VoteMenuPane(int voteType, const wchar_t *targetName);
    virtual ~VoteMenuPane();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual bool OnDismiss(const PaneEvent *event);
    virtual void OnPaint();
    virtual void DrawBackground();
    virtual void DrawBorder();

private:
    enum {
        kPromoteRow = 0,
        kDemoteRow = 1,
        kNoVoteRow = -1
    };

    unsigned char m_voteRowPressed;       // +0xf8
    signed char m_highlightedVoteRow;     // +0xf9
    unsigned char m_reservedFA[2];        // +0xfa..+0xfb alignment
    int m_voteType;                       // +0xfc; constructor context, not row submit flag
    wchar_t m_targetName[0x21];           // +0x100
};

extern VoteMenuPane *g_pVoteMenuPane;

static void GetVoteMenuItemRect(int row, Rect *rect);
static int HitTestVoteMenuItem(int x, int y);
static void SubmitVote(const wchar_t *targetName, unsigned char voteFlag);

[[CHILDREN]]
```

Notes:

- The helper prototypes are needed because current child body order calls `HitTestVoteMenuItem`, `GetVoteMenuItemRect`, and `SubmitVote` before their static definitions.
- The class shell deliberately does not include method bodies. The exact by-memory children own those bodies.
- If the validator/source style later requires helper prototypes above the class, keep the same declarations and semantics; the key requirement is that prototypes precede the out-of-class method bodies.
- `m_voteType` remains intentionally broad. Do not rename it to `m_voteFlag`, `m_isPromote`, `m_targetId`, or a narrowed enum unless constructor caller/allocation evidence is recovered.

## Constructor Child Recommendation

Recommended support-child update for [UID:0002LQ] `by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md` if this report is accepted:

- Raise `COMPLETION` from `86` to `87`.
- Keep `CONFIDENCE:91`, `CANONICAL_OWNER:0000FX`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000P6`.
- Replace the stale "formal C++ remains blank until field declarations..." wording with current policy: the direct no-caller/raw state caps score but no longer blocks first-draft C++ because the body is a complete source-authored constructor and the class field declarations are now ready.
- Add first-draft C++:

```cpp
VoteMenuPane::VoteMenuPane(int voteType, const wchar_t *targetName)
    : Pane(1)
{
    g_pVoteMenuPane = this;
    m_voteRowPressed = false;
    m_voteType = voteType;
    m_highlightedVoteRow = kNoVoteRow;
    wcscpy_s(m_targetName, 0x21, targetName);
}
```

Constructor source-shape caveats to preserve:

- Do not manually emit vtable stores.
- Do not convert `Pane(1)` to a visibility flag. The B001 base-constructor recheck resolved this as the pane mode/config byte.
- Do not narrow `voteType` beyond broad constructor context until caller evidence is found.
- Preserve negative direct-route evidence: no rel32 call/jump refs, no VA dword hits, and no recovered allocation/factory path to `0x005558d0`.

## Recommended Target Changes

For `by-class/VoteMenuPane.md`:

- Change metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:0000P6`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000P6`
  - `EMITTER_POSITION_OPTIONAL:0`
- Populate the formal C++ block with the class shell above.
- Replace the status cap language that says final source/code remains medium because IDA does not model `0x005558d0` as a function and helper names are not final. New text should say:
  - class-level declaration C++ is ready under the current combined 85/85 gate;
  - the raw constructor's no-direct-caller state still caps score below final audit but does not block class declaration or constructor first draft;
  - exact original helper spellings remain inferred, while source-facing names are stable enough for first draft;
  - scalar deleting destructor and adjustor thunks remain generated-binary support.
- Add or update notes that generated output currently lacks the class declaration/prototype layer, and that the class page should emit before child method bodies.
- Preserve rejected alternatives:
  - not `BulletinSession` helper ownership;
  - not CashShop or inbound packet handler ownership;
  - not RightButtonMenuPane ownership for VoteMenuPane methods/helpers, although RightButtonMenuPane closes both menus after submit;
  - not compiler glue for ordinary destructor or source helpers;
  - not a passive unresolved blocker just because the raw constructor lacks direct static callers.

## Recommended Support-Doc Changes

For `by-file/VoteMenuPane.md`:

- Raise from `88/85` to `89/88` if the class shell and constructor-child first draft are accepted.
- Replace any wording that treats the generated `class_BulletinSession.cpp` or old helper placement as active. The current source route is `NexusTK/ui/menu/VoteMenuPane.cpp`.
- Add the class-shell/prototype conclusion: the file should carry `VoteMenuPane` declaration/prototypes first, then exact child method/helper bodies.
- Document the exact source split:
  - class shell and declarations on [UID:0000FX];
  - source-authored destructor/mouse/dismiss/paint/background/border on [UID:0002LR]-[UID:0002LW];
  - file-local helpers on [UID:0002LX]-[UID:0002LZ];
  - compiler-generated adjustor/scalar-deleting destructor no-code support;
  - global singleton declaration/definition from `g_pVoteMenuPane` support.

For `by-type/by-struct/VoteMenuPaneLayout.md`:

- Raise from `85/89` to `87/90` if class field declarations are accepted.
- Replace stale "below final-source gate" style wording with current policy: layout support itself may remain a no-code generated-binary support page, while the class page now emits the declaration that names the tail fields.
- Preserve exact layout details:
  - `+0xf8 m_voteRowPressed`
  - `+0xf9 m_highlightedVoteRow`
  - `+0xfa..+0xfb` padding
  - `+0xfc m_voteType`
  - `+0x100 wchar_t m_targetName[0x21]`
  - total tail reaches through `0x144` allocation/free size.

For `by-type/by-vtable/VoteMenuPaneVtables.md` and `by-memory/0x00622ff4-0x00623084.VoteMenuPaneVtableData.md`:

- No score change required.
- Replace any stale "C++ remains blank under old 95/95 gate" wording with current policy:
  - vtable data remains no-code/generated-binary support;
  - class and method children may emit source C++;
  - destructor adjustor thunks and scalar deleting destructor are compiler-generated products of the class declaration/destructor.
- Add the direct PE vtable-store recheck if not already present: three vtable base immediates are in constructor, ordinary destructor, and scalar deleting destructor lifecycle stores.

For `by-global/g_pVoteMenuPane.md` and `by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md`:

- Raise to `87/91` if formal singleton C++ is accepted.
- Replace old threshold language with current policy and emit, or route support to emit, the source global:

```cpp
VoteMenuPane *g_pVoteMenuPane = NULL;
```

- Preserve zero-initialized live bytes and lifecycle refs:
  - constructor publishes `this`;
  - ordinary destructor clears it;
  - scalar deleting destructor clears it as compiler glue;
  - RightButtonMenuPane uses it as part of right-click/vote menu cleanup.

For `by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md`:

- Keep as reconstructable aggregate/index only if current policy treats it as a source-bearing island; otherwise leave formal code blank and route exact method bodies through children.
- Replace stale old-gate wording with current exact split:
  - class shell now emits at [UID:0000FX];
  - raw constructor can emit first-draft C++ at [UID:0002LQ] if accepted;
  - method bodies emit from exact children;
  - aggregate should not duplicate child bodies.

For `by-memory/0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit.md`:

- No C++ needed on the aggregate. Exact helper bodies already emit from [UID:0002LY] and [UID:0002LZ].
- Preserve the helper split and owner/file-local route.

For `by-memory/0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor.md`:

- Keep C++ blank.
- Add a short cross-reference to the new class declaration if accepted, making clear this wrapper is generated from the class destructor/delete form rather than source-authored separate C++.

## Open Questions Closed Or Narrowed

- Raw constructor reachability:
  - Closed as "live but no direct static route recovered." The best supported conclusion is retained out-of-line class constructor, not dead code. Evidence is lifecycle/vtable/global consistency and exact constructor body shape. Negative evidence remains important: no rel32 caller, no VA literal hit, and no allocation/factory route found.
- `m_voteType` exact semantics:
  - Narrowed but not fully closed. It is constructor context stored at `+0xfc`; it is not the Promote/Demote row flag because submit flags come from clicked row. No child in the recovered island reads it. Keep `int voteType` and document that no safer enum/name exists yet.
- Original helper spellings:
  - Not recoverable from current evidence. Use source-facing names `GetVoteMenuItemRect`, `HitTestVoteMenuItem`, and `SubmitVote` because their roles, caller routes, and file-local placement are strong. Score stays below final audit to reflect inferred spellings.
- Packet opcode/submode/flag:
  - Closed for behavior. It is outbound opcode `0x46`, submode `0`, target length/name bytes, and vote flag `1` for Promote row `0`, `0` for Demote row `1`.
- RightButtonMenuPane relationship:
  - Closed as caller/lifecycle coordination, not ownership. VoteMenuPane owns the vote popup source; RightButtonMenuPane owns the context-menu cleanup helper that closes both right-click and vote menus.
- Scalar deleting destructor:
  - Closed as no-code compiler-generated wrapper. It should not be represented as a separate handwritten source method.
- Class/file C++ readiness:
  - Closed as ready for declaration-level class C++ with child insertion and helper prototypes. The constructor child is also first-draft ready if the supervisor accepts this report's field declaration and source-shape recommendations.

## Score And Metadata Recommendation

| UID | Page | Current | Recommended | Rationale |
| --- | --- | ---: | ---: | --- |
| 0000FX | `by-class/VoteMenuPane.md` | `86/85` | `88/90` | Class shell, fields, helper prototypes, child route, packet behavior, singleton lifecycle, and no-code compiler-glue policy are resolved. Remaining caps are raw constructor no-direct-caller, broad `m_voteType`, and inferred helper spellings. |
| 0000P6 | `by-file/VoteMenuPane.md` | `88/85` | `89/88` | File route/source split is now strong and current generated owner pollution is rejected. |
| 0002LQ | raw constructor child | `86/91` | `87/91` | Constructor first-draft C++ is ready after class field declarations; no direct caller still caps confidence. |
| 0001WH | layout support | `85/89` | `87/90` | Class declaration can now name the exact tail fields. |
| 0000SP / 0001Q0 | singleton global docs | `86/90` | `87/91` | Zero-initialized source global C++ is ready if accepted. |
| 0001G3 | scalar deleting destructor | `85/91` | no change | Generated wrapper no-code policy remains correct. |
| 0002LR-0002LZ | exact method/helper children | already first-draft ready/populated | no change required | Existing child C++ and score direction remain valid. |

## Exact Future Implementation Checklist

If the supervisor accepts this report, send B014 an implementation callback with this checklist:

1. Edit only the accepted target/support docs. Do not edit `by-memory/-coverage-report.md`.
2. Update `by-class/VoteMenuPane.md` metadata to `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000P6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P6`, and `EMITTER_POSITION_OPTIONAL:0`.
3. Insert the exact declaration-level class C++ block from this report, with `[[CHILDREN]]` after the class declaration and helper prototypes before child bodies.
4. Replace stale class status text with current gate/source-quality reasoning, including no-direct-caller constructor cap, resolved row/packet semantics, resolved field names, and scalar destructor no-code policy.
5. Update `by-file/VoteMenuPane.md` with the source split, owner route, class declaration/prototype layer, rejection of `BulletinSession`/CashShop/inbound alternatives, and score `89/88` if accepted.
6. Update `by-type/by-struct/VoteMenuPaneLayout.md` with class-declaration readiness and the exact tail fields; raise to `87/90` if accepted.
7. Update `by-type/by-vtable/VoteMenuPaneVtables.md` and vtable data support only as needed to remove old-gate wording and preserve vtable/generated-binary no-code policy.
8. Update `by-global/g_pVoteMenuPane.md` and `by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md` if accepted to emit or document `VoteMenuPane *g_pVoteMenuPane = NULL;`, zero initialization, constructor publish, destructor clears, scalar destructor glue clear, and RightButton cleanup use.
9. Update `by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md` if accepted to raise to `87/91`, add the first-draft constructor C++, preserve no-direct-route negative evidence, and replace the stale "blank until field declarations" hold.
10. Update `by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md` and `by-memory/0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit.md` only to reconcile aggregate policy and remove stale old-gate language; do not duplicate child method bodies.
11. Leave [UID:0001G3] scalar deleting destructor formal C++ blank; add only clarifying cross-references if useful.
12. Run scoped validators for each edited file and run autogen.
13. Keep exact supervisor-owned coverage replacement text in notes/report; the B agent must not edit `by-memory/-coverage-report.md`.

## Exact Pending Coverage Text

Class coverage row replacement for `by-class/-coverage-report.md` if the supervisor applies class coverage:

```text
- [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md) : reconstructable : 88% : strong : B014 2026-06-19 class source-quality pass raises the class to `88/90`, keeps source root [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md), and makes declaration-level C++ ready with a `Pane`-derived class shell, helper prototypes, `[[CHILDREN]]`, row constants, `m_voteRowPressed` +0xf8, `m_highlightedVoteRow` +0xf9, `m_voteType` +0xfc as constructor context, and `m_targetName[0x21]` +0x100. Direct PE/Capstone recheck confirms no raw constructor call/VA route, lifecycle refs through vtables/global, method/helper caller routes, `Promote`/`Demote` strings, `SUBWIN` resource use, outbound opcode `0x46` packet layout, and compiler-generated adjustor/scalar-destructor no-code policy.
```

File coverage row replacement for `by-file/-coverage-report.md` if the supervisor applies file coverage:

```text
- [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md) : reconstructable : 89% : strong : B014 2026-06-19 class/file source-quality pass keeps `NexusTK/ui/menu/VoteMenuPane.cpp`, raises confidence after class shell and exact child C++ decisions, resolves generated BulletinSession/CashShop owner pollution, documents file-local `GetVoteMenuItemRect`/`HitTestVoteMenuItem`/`SubmitVote` helpers, outbound opcode `0x46` packet route through `g_packetSender`, `g_pVoteMenuPane` singleton source global, and compiler-generated adjustor/scalar-delete no-code policy.
```

No supervisor-owned `by-memory/-coverage-report.md` replacement is required for a class-only implementation. If the supervisor also accepts the constructor-child first-draft C++ recommendation, replace the [UID:0002LQ] row with:

```text
      - [UID:0002LQ][0x005558d0-0x00555945.VoteMenuPaneRawConstructor](by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md) 0x005558d0-0x00555945 | raw constructor-shaped method | VoteMenuPaneRawConstructor : reconstructable : 87% : strong : B014 2026-06-19 class source-quality pass supersedes the old constructor-C++ hold after class field declarations became ready; direct PE/Capstone still finds zero rel32 call/jump refs and zero VA dword hits for the raw start, but the body is a complete `thiscall` constructor (`ret 8`) with `Pane::Pane(mode=1)`, `g_pVoteMenuPane` publish, `m_voteRowPressed` clear, `m_voteType` context store, three VoteMenuPane vtable installs, `m_highlightedVoteRow = -1`, `wcscpy_s(m_targetName, 0x21, targetName)`, lifecycle refs through ordinary/scalar destructors and vtables, exact `0xcc` padding, direct class owner [UID:0000FX], and first-draft constructor C++ readiness using the intentionally broad `int voteType` name.
```

If the supervisor also accepts singleton global C++, replace or append the relevant global/support coverage rows with text equivalent to:

```text
- [UID:0000SP][g_pVoteMenuPane](by-global/g_pVoteMenuPane.md) : reconstructable : 87% : strong : B014 2026-06-19 VoteMenuPane class pass confirms this is the source singleton `VoteMenuPane *g_pVoteMenuPane = NULL;`, zero-initialized at [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md), published by the raw constructor, cleared by the ordinary destructor and scalar deleting destructor glue, and consumed by RightButtonMenuPane cleanup; old 95/95 no-code threshold language is superseded by the current combined-score gate.
```

## Validation Commands Needed On Implementation

Run from `source-3/project-documentation` after any accepted implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000FX-VoteMenuPane-class-source-quality-removed.md](0000FX-VoteMenuPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run validators for files actually edited, plus autogen after emitter/C++ changes.

## IDA Rename, Type, And Comment Recommendations

High confidence:

- Rename `0x005558d0` to `VoteMenuPane::VoteMenuPane`.
- Type `0x005558d0` as `VoteMenuPane *__thiscall VoteMenuPane_ctor(VoteMenuPane *this, int voteType, const wchar_t *targetName)` or the closest local IDA form.
- Rename `0x00555950` to `VoteMenuPane::~VoteMenuPane`.
- Rename `0x005559c0` to `VoteMenuPane::OnMouseEvent`.
- Rename `0x00555ae0` to `VoteMenuPane::OnDismiss`.
- Rename `0x00555af0` to `VoteMenuPane::OnPaint`.
- Rename `0x00555c70` to `VoteMenuPane::DrawBackground`.
- Rename `0x00555cf0` to `VoteMenuPane::DrawBorder`.
- Rename `0x00556020` to `GetVoteMenuItemRect`.
- Rename `0x00556070` to `HitTestVoteMenuItem`.
- Rename `0x00556100` to `SubmitVote`.
- Rename `0x0069ba38` to `g_pVoteMenuPane`.
- Apply class struct tail fields `m_voteRowPressed`, `m_highlightedVoteRow`, `m_voteType`, and `m_targetName[0x21]`.

Medium/high confidence:

- Comment `m_voteType` as constructor context with no recovered consumer in the current island; not the Promote/Demote submit flag.
- Comment packet byte `0x46` as outbound vote-menu opcode and second byte `0` as submode/reserved byte.
- Comment row flag mapping: row `0` Promote sends `1`; row `1` Demote sends `0`.
- Comment `0x00556228` and `0x00556233` as secondary-base scalar-deleting destructor adjustor thunks.
- Comment `0x00556320` as compiler-generated scalar deleting destructor wrapper, not handwritten source.

Rejected IDA directions:

- Do not keep `sub_5558D0`, `sub_556070`, or `sub_556100` as unresolved raw names in documentation once the callback is accepted.
- Do not name the helpers under `BulletinSession`, `CashShop`, or RightButton ownership.
- Do not name `0x00556320` as the ordinary destructor.
- Do not label the constructor argument at `+0xfc` as the submit flag unless caller evidence later proves it.

## Changed Files In This Pass

Created only:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/0000FX-VoteMenuPane-class-source-quality.md`

No validators were run because this was a report-only pass and no by-* documentation was edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0000FX-VoteMenuPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0000FX"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000FX-VoteMenuPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0000FX-VoteMenuPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000FX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
