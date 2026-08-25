*** UID:000017 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class BrowserDialog : public BrowserPane,
                      public Singleton<BrowserDialog>
{
public:
    BrowserDialog(int,
                  const OLECHAR *initialUrl,
                  int width,
                  int height);
    virtual ~BrowserDialog();

    void NavigateToUrl(const wchar_t *url);

    virtual void OnCloseStateChanged(int state, int reason);
    virtual bool OnInputEventWithBrowserReposition(InputEvent *event);
    virtual void DrawSelectedControlFrame();
    virtual void DrawContentArea();
    virtual void DrawFrameChrome();

protected:
    int GetChildRect(short childId, RectBounds *outBounds) const;

    BrowserControlPane *m_browserControlPane; // +0x26c
    int m_width;                              // +0x278, overlaps the empty Singleton base
    int m_height;                             // +0x27c
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BrowserDialog

## Summary

`BrowserDialog` is the singleton URL browser dialog used by the newer browser-control path. It owns a title area and an owning pointer to a separately allocated `BrowserControlPane`, forwards URL navigation into an already-open browser pane, and owns exact split children for the constructor, ordinary destructor, and `NavigateToUrl` plus the broader BrowserDialog virtual/helper cluster. Current RTTI and constructor lowering support the source-facing inheritance direction `BrowserDialog : public BrowserPane, public Singleton<BrowserDialog>`: BrowserPane supplies the primary pane layout and `Singleton<BrowserDialog>` is a non-virtual empty base at complete-object offset `+0x278`, overlapping `m_width` through empty-base optimization.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp` or `browser/BrowserDialog.cpp`
- Confidence: strong for the browser module and parent attachment; medium-high for exact file split between a monolithic `Browser.cpp` and a separate `BrowserDialog.cpp`

## Methods

| Range | Current interpretation | Notes |
| --- | --- | --- |
| [UID:000409][0x0046a8c0-0x0046a8d7.BrowserDialogNavigateToUrl](by-memory/0x0046a8c0-0x0046a8d7.BrowserDialogNavigateToUrl.md) | `BrowserDialog::NavigateToUrl` | Thin singleton/dialog wrapper that forwards the URL through the owning pointer to the separately allocated BrowserControlPane child at `0x0046bd30`; first-draft C++ is emitted by the exact child. |
| [UID:00040C][0x0046aa40-0x0046ad0a.BrowserDialogConstructor](by-memory/0x0046aa40-0x0046ad0a.BrowserDialogConstructor.md) | `BrowserDialog::BrowserDialog(int, const OLECHAR *, int, int)` | Source-ready constructor with an intentionally unnamed body-unused first argument, URL/width/height roles, `662x562` defaults, current/legacy layout branches, Singleton-base lifetime, owning BrowserControlPane pointer, and formal first-draft C++. |
| [UID:0004DH][0x0046ad10-0x0046ad39.BrowserDialogNonDeletingDestructor](by-memory/0x0046ad10-0x0046ad39.BrowserDialogNonDeletingDestructor.md) | `BrowserDialog::~BrowserDialog` ordinary destructor | Clears `dword_67AB98` / `g_pBrowserDialog`; vtable restoration and base dialog teardown are compiler/destructor-chain effects. The scalar deleting wrapper is tracked separately. |
| `0x0046ad40-0x0046ad7b` | `BrowserDialog::OnCloseStateChanged(int state, int reason)` | On `state == 0`, shuts down the pointed-to `BrowserControlPane` at `+0x26c` / `m_browserControlPane`, runs close/cleanup slots, and queues/unregisters through `g_pApplicationCleanupQueue`; no member-null store is observed in this base BrowserDialog body. |
| `0x0046ad80-0x0046aea8` | `BrowserDialog::OnInputEventWithBrowserReposition(InputEvent *event)` | Boolean one-argument derived input/move override that delegates to base input, uses `g_activeBrowserControlPane` and the hosted HWND at BrowserControlPane `+0x11c`, repositions the pointed-to browser child window, and refreshes `g_pScreenPane`. |
| `0x0046aeb0-0x0046b02d` | `BrowserDialog::DrawSelectedControlFrame` | Draws state-dependent browser-dialog UI pieces after clearing transient pane state and reading the selected child/control rectangle. |
| `0x0046b030-0x0046b0c3` | `BrowserDialog::DrawContentArea` | Uses the resolved `WBOARDBK.EPF` / `WBOARDBK.PAL` literals to draw/tile-fill the browser content area. |
| `0x0046b0d0-0x0046b4af` | `BrowserDialog::DrawFrameChrome` | Tiles the board-frame chrome using the resolved `WEBBOARD.EPF` / `WEBBOARD.PAL` literals. |
| `0x0046b4b0-0x0046b51d` | `BrowserDialog::GetChildRect(short childId, RectBounds *outBounds) const` | Nonvirtual constructor-called child-rect helper: id `0` is the title/icon rect, id `1` is the browser-content rect, and other ids return `childId - 1`. |
| [UID:00033A][0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor](by-memory/0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor.md) | scalar deleting destructor glue | MSVC deleting-destructor wrapper covered by exact ordinary destructor child [UID:0004DH][0x0046ad10-0x0046ad39.BrowserDialogNonDeletingDestructor](by-memory/0x0046ad10-0x0046ad39.BrowserDialogNonDeletingDestructor.md); no handwritten wrapper body. It clears the same singleton, restores BrowserPane vtables, runs base teardown, and adds only delete-flag/free-path compiler mechanics. |

## Object Layout And Class Surface

| Offset / surface | Source-facing declaration | Evidence and disposition |
| --- | --- | --- |
| bases | `BrowserPane`, `Singleton<BrowserDialog>` | BrowserPane-to-BrowserDialog vptr construction order plus RTTI base descriptor `0x00642f14`, `mdisp=0x278`, `pdisp=-1`, `vdisp=0`. |
| `+0x26c` | `BrowserControlPane *m_browserControlPane` | Both constructor branches separately allocate `0x338` bytes, store the returned pointer, register it, and later navigation/close/reposition consumers dereference it. Historical embedded-object wording is superseded. |
| `+0x278` | `int m_width` | Input width or default `662`; overlaps the empty Singleton base through EBO. |
| `+0x27c` | `int m_height` | Input height or default `562`; complete object size is `0x280`. |
| exact children | constructor, virtual destructor, `NavigateToUrl` | UID00040C, UID0004DH, and UID000409 provide formal definitions routed by post-class `[[CHILDREN]]`. |
| primary overrides | `DrawSelectedControlFrame`, `OnCloseStateChanged`, `DrawContentArea`, `DrawFrameChrome` | Fresh BrowserPane/BrowserDialog vtable diff places these at primary offsets `+0x44`, `+0x48`, `+0x50`, and `+0x54`. |
| secondary override | `OnInputEventWithBrowserReposition(InputEvent *)` | Fresh vtable diff places the boolean one-stack-argument override at secondary `+0x04` / cell `0x00613414`. |
| nonvirtual helper | `GetChildRect(short, RectBounds *) const` | Two direct constructor calls, no vtable cell, exact id/formula behavior. |

The class block declares all nine sufficiently resolved methods. BrowserPane-identical vtable slots are inherited and not redundantly declared. [UID:00033A][0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor](by-memory/0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor.md) and secondary deleting adjustors are compiler-generated from the virtual destructor declaration and remain excluded. UID00020X retains blank method bodies under its accepted low-level draw-helper/field disposition; that body-level limitation no longer leaves a class-declaration gap.

## Evidence

- An evidence-time IDA MCP recheck on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`; this records that pass and does not assert the session remains available.
- Evidence-time IDA analysis identified `NavigateToUrl` at `0x0046a8c0-0x0046a8d7`; it is called from `0x00513e7f` inside the `0x00513da0` MapPane packet helper and invokes the navigation helper at `0x0046bd30` through the owning pointer to the separately allocated BrowserControlPane child.
- The same evidence pass identified the constructor at `0x0046aa40-0x0046ad0a`, with direct callers at `0x00513ebe` inside the MapPane packet helper and `0x005a7079` inside `UserPane::OnKeyEvent`.
- Constructor data refs install BrowserPane vtables at `0x006132ec`, `0x00613360`, and `0x00613390`, then BrowserDialog vtables at `0x0061339c`, `0x00613410`, and `0x00613440`.
- Constructor refs write `dword_67AB98` at `0x0046aab7` and `0x0046aabe`, call the child-rect helper at `0x0046ab1d` and `0x0046ab5f`, and call the separately allocated `BrowserControlPane` constructor at `0x0046ab86`/`0x0046ac95` before storing the pointer at `+0x26c`.
- Singleton `dword_67AB98` xrefs are now mapped: constructor writes at `0x0046aab7`/`0x0046aabe`, destructor clear at `0x0046ad10`, Browser-family clears at `0x00470220` and `0x00470586`, and reads from MapPane/UserPane/browser-launch paths at `0x00508d68`, `0x00513e67`, `0x005145ac`, `0x005a7005`, and `0x005a7037`.
- Vtable slots in the `0x0061339c-0x00613440` BrowserDialog group point to the destructor/delete thunks and virtual helpers; the key source-behavior slots include `0x006133e0 -> 0x0046aeb0`, `0x006133e4 -> 0x0046ad40`, `0x006133ec -> 0x0046b030`, `0x006133f0 -> 0x0046b0d0`, and `0x00613414 -> 0x0046ad80`.
- Evidence-time IDA analysis confirms the child-rect helper returns title bounds `(width - 63) / 2, height - 32, 63, 24` for slot `0`, and browser content bounds `11, 42, width - 22, height - 82` for slot `1`.
- Byte checks confirm `0x0046ad0a-0x0046ad10` and `0x0046b51d-0x0046b520` are `0xcc` alignment padding between the constructor, virtual cluster, and `BrowserControlPane` constructor.
- B001-024 exact child [UID:00033A][0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor](by-memory/0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor.md) documents `sub_470580`, vtable ref `0x0061339c`, adjustor callers at `0x00470294`/`0x0047029f`, singleton clear `dword_67AB98`, base teardown, and delete flag behavior.
- B009 2026-07-02 resolves [UID:00033A][0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor](by-memory/0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor.md) as BrowserDialog-specific MSVC scalar deleting destructor glue, not handwritten source. The primary vtable slot `0x0061339c` points to the wrapper; secondary slices `0x00613410` and `0x00613440` route through adjustors at `0x0047028e` and `0x00470299` that subtract `0xa0` and `0xa4`. The source-authored behavior is exact ordinary destructor child [UID:0004DH][0x0046ad10-0x0046ad39.BrowserDialogNonDeletingDestructor](by-memory/0x0046ad10-0x0046ad39.BrowserDialogNonDeletingDestructor.md), which clears `g_pBrowserDialog`; inherited BrowserPane view restoration and base teardown are compiler/destructor-chain effects.
- B002 2026-06-17 source-quality reanalysis resolves the stale draw-resource pointer names for [UID:00020X][0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals](by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md): `off_60DB5C`/`off_60DB78` are `WBOARDBK.EPF`/`WBOARDBK.PAL`, and `off_60DB94`/`off_60DBB0` are `WEBBOARD.EPF`/`WEBBOARD.PAL`. The same pass rejects absorbing these methods into `BrowserPane`, `DialogPane`, WebBoard, Ranking, or resource ownership; the vtable block and `g_pBrowserDialog` lifecycle keep this cluster in `BrowserDialog`.
- B002 2026-06-20 split implementation resolves the earlier `0x0046a860-0x0046ad0a` aggregate as a non-emitting index. BrowserDialog directly owns [UID:000409][0x0046a8c0-0x0046a8d7.BrowserDialogNavigateToUrl](by-memory/0x0046a8c0-0x0046a8d7.BrowserDialogNavigateToUrl.md) and [UID:00040C][0x0046aa40-0x0046ad0a.BrowserDialogConstructor](by-memory/0x0046aa40-0x0046ad0a.BrowserDialogConstructor.md); BrowserPane owns the intervening BrowserPane methods.
- B012 2026-06-19 BrowserPane class reanalysis rechecked the stale BrowserPane direct-method question for `0x0046ad80-0x0046aea8`. The BrowserDialog vtable slot `0x00613414` points to this method, and the adjacent [UID:00020X][0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals](by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md) cluster owns the surrounding BrowserDialog virtuals. BrowserPane remains the inherited base dependency only; direct ownership stays here.
- Evidence collected during B003 MCP session `359c7886` resolved the BrowserDialog base layout and destructor route without changing class-wide score or formal C++. RTTI hierarchy descriptor `0x00642ec0` has nine entries; base descriptor `0x00642f14` names `Singleton<BrowserDialog>` with `mdisp=0x278`, `pdisp=-1`, and `vdisp=0`. Constructor `0x0046aa40` installs BrowserPane views, publishes the singleton around the `+0x278` base, then installs BrowserDialog views. Primary cell `0x0061339c` and secondary cells `0x00613410`/`0x00613440` route to scalar wrapper `0x00470580` and `-0xa0`/`-0xa4` adjustors, so delete flags, vptr restoration, and base teardown remain compiler output while [UID:0004DH][0x0046ad10-0x0046ad39.BrowserDialogNonDeletingDestructor](by-memory/0x0046ad10-0x0046ad39.BrowserDialogNonDeletingDestructor.md) retains the source-visible singleton clear.
- Evidence reconfirmed during B005 MCP session `545b4991` established exact method sizes `0x17`, `0x2ca`, `0x29`, `0x3b`, `0x128`, `0x17d`, `0x93`, `0x3df`, and `0x6d` for navigation, constructor, destructor, close, input, three draw/helper methods, and child rectangle. Primary BrowserPane-versus-BrowserDialog differences are deleting slot `+0x00` and source overrides `+0x44/+0x48/+0x50/+0x54`; secondary differences are deleting adjustor `+0x00` and input override `+0x04`; remaining compared source-method cells are inherited-identical. This is evidence-time provenance, not a claim that session `545b4991` remains alive.
- Fresh disassembly gives `void(int,int)`/`retn 8` for close, boolean-sized return plus one argument/`retn 4` for input, zero stack arguments for all three draw overrides, and `int(short,RectBounds *)`/`retn 8` for GetChildRect. Xrefs bind the five overrides only to cells `0x006133e0`, `0x006133e4`, `0x006133ec`, `0x006133f0`, and `0x00613414`; GetChildRect has only the two constructor calls.
- Current generated `NexusTK/browser/Browser.cpp` before this callback emits standalone UID0004DH destructor, omits UID000409, and leaves UID000017/UID00020X/UID00040C as empty markers. The populated class shell and post-class `[[CHILDREN]]` route are required for the accepted exact child definitions to form one source unit.

## Open Questions

- Constructor parameters, pointer/dimension fields, child-rect signature, inheritance, and all sufficiently resolved class declarations are closed by the accepted UID00040C/B005 evidence and the formal class shell.
- Exact original virtual names/access sections remain inferred. Current UID00020X staging, sibling WebBoard signatures, live argument cleanup, and exact vtable positions support the declarations now; this is a confidence cap, not permission to omit compile-required declarations.
- Formal **bodies** for the combined [UID:00020X][0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals](by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md) remain intentionally blank under that page's accepted low-level GrafPort/resource helper and inherited draw-state rationale. All seven methods are declared here, so no class-surface work is deferred.
- [UID:00033A][0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor](by-memory/0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor.md) is no-code compiler wrapper coverage for exact ordinary destructor child [UID:0004DH][0x0046ad10-0x0046ad39.BrowserDialogNonDeletingDestructor](by-memory/0x0046ad10-0x0046ad39.BrowserDialogNonDeletingDestructor.md), not a separate source-method blocker or coverage route to broad aggregate UID00020X.
- The exact original source split between `Browser.cpp` and `BrowserDialog.cpp` remains unproven. Retain the accepted Browser emitter; this does not affect declaration/body correctness.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md), [UID:000019][BrowserPane](by-class/BrowserPane.md)
- Memory: [UID:0000Z5][0x0046a860-0x0046ad0a.BrowserPaneAndDialog](by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md), [UID:00020X][0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals](by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md), [UID:0004DH][0x0046ad10-0x0046ad39.BrowserDialogNonDeletingDestructor](by-memory/0x0046ad10-0x0046ad39.BrowserDialogNonDeletingDestructor.md), [UID:00033A][0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor](by-memory/0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor.md)

## Changes

- 2026-07-12 B005 UID00040C source-quality implementation callback:
  - Raised `87/89 -> 89/91`; preserved owner/emitter `0000HV`, reconstructable true, and all existing class routes.
  - Applied the complete nine-method class declaration with BrowserPane/Singleton inheritance, exact constructor, virtual destructor, NavigateToUrl, five BrowserDialog-specific virtual overrides, const GetChildRect, pointer/dimension fields, and post-class `[[CHILDREN]]`.
  - Added method/vtable/ABI proof collected during MCP session `545b4991`, object layout/EBO detail, generated-route defect, inherited/compiler exclusions, pointer correction, body-level UID00020X disposition, and closed constructor/class-surface questions without removing historical evidence; the session reference records evidence time only.

- 2026-07-12 B003 UID0004DH support sync:
  - Score and formal C++ remain unchanged. Added current nine-entry RTTI hierarchy evidence, `Singleton<BrowserDialog>` base at `+0x278`, BrowserPane-primary inheritance direction, constructor publication order, and scalar-wrapper/adjustor dispatch separation. Broader constructor signatures, virtual declarations, and physical Browser source split remain class-level gaps.
- 2026-07-02 B009 UID00033A implementation callback:
  - Score unchanged at `87/89`.
  - Summary/evidence: updated the UID00033A method/evidence wording to classify it as BrowserDialog-specific MSVC scalar deleting destructor glue covered by exact ordinary destructor child [UID:0004DH][0x0046ad10-0x0046ad39.BrowserDialogNonDeletingDestructor](by-memory/0x0046ad10-0x0046ad39.BrowserDialogNonDeletingDestructor.md), preserving owner/emitter routing while rejecting a handwritten wrapper body, BrowserPane ownership, no-owner blank-emitter treatment, and the rejected broad UID00020X coverage route. Evidence includes primary vtable `0x0061339c`, secondary slices `0x00613410`/`0x00613440`, adjustors at `0x0047028e`/`0x00470299`, `g_pBrowserDialog` clear, BrowserPane vptr restores, base teardown, and delete-flag/free-path compiler mechanics.
- 2026-06-20 B002 Rule 26 split implementation:
  - Before: `85/88`, with `NavigateToUrl` and the constructor still partly represented through the mixed [UID:0000Z5][0x0046a860-0x0046ad0a.BrowserPaneAndDialog](by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md) aggregate.
  - After: `87/89`, with exact BrowserDialog children [UID:000409][0x0046a8c0-0x0046a8d7.BrowserDialogNavigateToUrl](by-memory/0x0046a8c0-0x0046a8d7.BrowserDialogNavigateToUrl.md) and [UID:00040C][0x0046aa40-0x0046ad0a.BrowserDialogConstructor](by-memory/0x0046aa40-0x0046ad0a.BrowserDialogConstructor.md) linked.
  - Summary/evidence: incorporated B002's split decision, direct `NavigateToUrl` owner/callee evidence, `BrowserControlPane` child at `+0x26c`, constructor callers `0x00513ebe` and `0x005a7079`, vtable install order, `g_pBrowserDialog` writes, child-rect helper calls, constructor blank-C++ blocker list, and Browser source-root routing.
- 2026-06-21 B012 BrowserPane owner-boundary sync:
  - Score unchanged at `87/89`.
  - Summary/evidence: B012 confirms `0x0046ad80-0x0046aea8` is BrowserDialog-owned through vtable slot `0x00613414`, rejecting stale BrowserPane direct-method wording while preserving BrowserPane as the inherited base dependency.
- 2026-06-17 B002 source-quality execution:
  - Method table now uses the inferred source-facing names from B002 for the BrowserDialog destructor, close-state callback, input/reposition override, selected-control draw helper, content draw helper, frame chrome helper, and child-rect helper.
  - Resource wording now resolves `off_60DB5C`/`off_60DB78` to `WBOARDBK.EPF`/`WBOARDBK.PAL` and `off_60DB94`/`off_60DBB0` to `WEBBOARD.EPF`/`WEBBOARD.PAL`.
  - Added owner-pollution rejection for BrowserPane/DialogPane/WebBoard/Ranking/resource routes and preserved the formal-C++ hold for the combined draw-helper cluster.

- 2026-06-10 B001-024 parent-gate repair:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`; scalar deleting destructor behavior was documented only in the class summary.
  - Changed to: `COMPLETION:85`, linked exact child [UID:00033A][0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor](by-memory/0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor.md).
  - Summary/evidence: IDA MCP results collected during that evidence pass confirmed `sub_470580` at `0x00470580-0x004705df`, vtable ref `0x0061339c`, adjustor callers, singleton clear `dword_67AB98`, BrowserPane vtable restore, base teardown, and delete flag behavior. This cleared the strict `85/85` parent gate for the destructor child at that historical stage and does not assert continued availability of the evidence session.
- 2026-06-04: Raised completion/confidence from `72/80` to `84/88`, marked reconstructable, and attached to [UID:0000HV][Browser](by-file/Browser.md).
  - Before: the page identified the constructor and virtual cluster but still carried stale provenance wording, was not attached to the Browser parent, and did not record the singleton/vtable/child-rect evidence with the specificity required to justify leaving the low-score queue.
  - After: evidence-time IDA results record the binary identity, exact method ranges, MapPane/UserPane callers, BrowserDialog vtable stores/slots, singleton reads and clears, separately allocated BrowserControlPane child construction and owning-pointer storage, child-rect arithmetic, and alignment padding. The older embedded-object interpretation is rejected and superseded.
  - Reasoning: the class is source-authored browser-module code and the parent file satisfies the documented attachment gate with current evidence. Final C++ remains blank because frame-resource typing, exact virtual names, and the one-file versus split-file decision are still below the 95/95 reconstruction bar.
- Before: this page only listed `NavigateToUrl` and the constructor, and its memory reference pointed at a range ending in `0x0046ad09`.
- Changed to: the constructor endpoint is now `0x0046ad0a`, and the adjacent destructor/virtual helper cluster at `0x0046ad10-0x0046b51d` is included.
- Summary/evidence: IDA MCP reports `sub_46AA40` ends at `0x0046ad0a`, and vtable xrefs place `sub_46AD40`, `sub_46AD80`, `sub_46AEB0`, `sub_46B030`, and `sub_46B0D0` in the BrowserDialog vtable region.

- What existed before: the page had browser-dialog evidence and prior range corrections, but completion/confidence metadata still read `0/0`.
- What it was changed to: scores were set to `72/80`.
- Summary and evidence: constructor, singleton behavior, BrowserControlPane ownership, and vtable-neighboring virtuals are documented; singleton typing and final source split remain open.
