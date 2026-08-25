*** UID:0000D7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SimpleHelpPane2 : public HelpPane,
                        public Singleton<SimpleHelpPane2>
{
public:
    SimpleHelpPane2(const wchar_t *text,
                    Pane *owner,
                    int x,
                    int y,
                    const RectBounds *anchorRect,
                    int timeoutMs,
                    int horizontalAlign,
                    int verticalAlign,
                    const FontStyle *style);
    virtual ~SimpleHelpPane2();

protected:
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    bool IsCursorInsideAnchorRect();

    RectBounds m_anchorRect;
};

extern SimpleHelpPane2 *g_pSimpleHelpPane2;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SimpleHelpPane2

## Status

- Likely source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- Address range: non-emitting split index [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) with exact source children [UID:00048K][0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor](by-memory/0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor.md), [UID:00048L][0x004c75e0-0x004c7609.SimpleHelpPane2Destructor](by-memory/0x004c75e0-0x004c7609.SimpleHelpPane2Destructor.md), [UID:00048M][0x004c7610-0x004c7620.SimpleHelpPane2OnAccept](by-memory/0x004c7610-0x004c7620.SimpleHelpPane2OnAccept.md) (source-facing `OnTimer` timeout callback; historical slug), [UID:00048N][0x004c7620-0x004c7668.SimpleHelpPane2HandleEvent](by-memory/0x004c7620-0x004c7668.SimpleHelpPane2HandleEvent.md), and [UID:00048O][0x004c7670-0x004c7680.SimpleHelpPane2OnCancel](by-memory/0x004c7670-0x004c7680.SimpleHelpPane2OnCancel.md), adjacent factory [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md), raw factory helpers [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md), with destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Declaration state: complete source-facing class declaration at source position `20`, closed before `[[CHILDREN]]`; exact child bodies remain the sole method emitters in positions `10/20/30/40/50`.
- Confidence: very strong for direct HelpPane/Singleton inheritance, EBO layout, vtable identity, singleton ownership, factory construction, timeout/event behavior, all three TimerHandler/EventHandler slot roles, and HelpPanes placement. Original access/header/helper/style spellings and the constructor's no-direct-xref result remain lexical caps only.

## Class Purpose

`SimpleHelpPane2` is a `HelpPane` plus empty `Singleton<SimpleHelpPane2>` subclass that adds an anchor rectangle and an auto-hide timer. Singleton base construction/destruction publishes and clears the active pointer; human methods convert a parent-relative anchor rectangle into local coordinates and hide the pane on relevant input/timer events.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SimpleHelpPane2` | [UID:00048K][0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor](by-memory/0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor.md) | Position `10`; constructs `HelpPane` and `Singleton<SimpleHelpPane2>`, stores `m_anchorRect` at `+0x224`, and schedules timer id 0 through the four-argument TimerHandler API. Vptr stores and singleton publication are compiler/base consequences. |
| `~SimpleHelpPane2` | [UID:00048L][0x004c75e0-0x004c7609.SimpleHelpPane2Destructor](by-memory/0x004c75e0-0x004c7609.SimpleHelpPane2Destructor.md) | Position `20`; empty human ordinary destructor. Three vptr restores, Singleton clear, and `HelpPane` tail teardown are compiler/base consequences. |
| `OnTimer` | [UID:00048M][0x004c7610-0x004c7620.SimpleHelpPane2OnAccept](by-memory/0x004c7610-0x004c7620.SimpleHelpPane2OnAccept.md) | Position `30`; TimerHandler-facet timeout callback recovers `this` with `this - 0xa4`, calls `Close()`, returns handled, and keeps the `SimpleHelpPane2OnAccept` file slug as historical. |
| `HandlePointerOrMouseEvent` | [UID:00048N][0x004c7620-0x004c7668.SimpleHelpPane2HandleEvent](by-memory/0x004c7620-0x004c7668.SimpleHelpPane2HandleEvent.md) | EventHandler pointer/mouse-family override at secondary slot `+4`: either button-down or cursor movement outside `m_anchorRect` schedules timer id 0 at zero delay with zero payload; y `+0x08` and x `+0x0c` feed `PointInRect(y,x,...)`; every path returns false and no removal occurs. Historical `HandleEvent` slug is retained only for path continuity. |
| `HandleKeyOrTextEvent` | [UID:00048O][0x004c7670-0x004c7680.SimpleHelpPane2OnCancel](by-memory/0x004c7670-0x004c7680.SimpleHelpPane2OnCancel.md) | EventHandler key/text-family override at secondary slot `+8`: closes without reading its Event argument and returns false. Historical `OnCancel` slug is retained only for path continuity. |
| `CreateSimpleHelpPane2` / `ShowSimpleHelpPane2` | [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md) | File-local factory that replaces the active singleton, constructs the popup, stores anchor bounds, and schedules the timer. |
| factory adapters / `IsCursorInsideAnchorRect` | [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md) | Raw-start helper cluster with first-draft formal C++: two file-local factory adapters and `SimpleHelpPane2::IsCursorInsideAnchorRect`, which returns true when the stored anchor rectangle is empty/invalid or when the current cursor is inside the screen-adjusted anchor rectangle. |
| `ScalarDeletingDestructor` | [UID:0003YY][0x004ce500-0x004ce55f.SimpleHelpPane2ScalarDeletingDestructor](by-memory/0x004ce500-0x004ce55f.SimpleHelpPane2ScalarDeletingDestructor.md) | Non-emitting compiler scalar deleting destructor wrapper; restores vtables, performs implicit Singleton/HelpPane teardown, interprets flags, optionally deletes storage, and guards exact size `0x234`. |

## Evidence Notes

- 2026-06-04 live IDA MCP confirms modeled function boundaries for `SimpleHelpPane2`: constructor `0x004c74b0-0x004c75d5`, ordinary teardown `0x004c75e0-0x004c7609`, UID00048M source-facing `OnTimer` / historical `OnAccept` slug at `0x004c7610-0x004c7620`, UID00048N pointer/mouse / historical `HandleEvent` slug at `0x004c7620-0x004c7668`, UID00048O key/text / historical `OnCancel` slug at `0x004c7670-0x004c7680`, factory `0x004c7680-0x004c77e0`, adjustor thunks `0x004ce377-0x004ce382` and `0x004ce382-0x004ce38d`, and scalar deleting destructor `0x004ce500-0x004ce55f`.
- The constructor calls [UID:000063][HelpPane](by-class/HelpPane.md) at `0x004c74ff`; its adjusted publish/fallback stores at `0x004c751b/0x004c7522` are compiler-inlined `Singleton<SimpleHelpPane2>` base construction. It installs vtables at `0x004c7537/0x004c753d/0x004c7547`, copies or clears the anchor rectangle at `this+0x224`, offsets it through `0x004b7e10`, and schedules timer id 0 through `0x005975e0` with delay plus two zero payload arguments.
- Live IDA names the three vtable views as `??_7SimpleHelpPane2@@6B@` at `0x0061ac6c`, `??_7SimpleHelpPane2@@6B@_0` at `0x0061acb8`, and `??_7SimpleHelpPane2@@6B@_1` at `0x0061ace8`. Key slots are `0x0061ac6c -> 0x004ce500`, secondary EventHandler pointer/mouse `0x0061acbc -> 0x004c7620`, secondary key/text `0x0061acc0 -> 0x004c7670`, and tertiary TimerHandler `0x0061acec -> 0x004c7610`.
- Vtable writes/refs line up across lifecycle paths: constructor writes the three views at `0x004c7537/0x004c753d/0x004c7547`; ordinary teardown rewrites them at `0x004c75e0/0x004c75e6/0x004c75f0`; factory construction writes the primary view at `0x004c7746`; and the scalar deleting destructor rewrites them at `0x004ce506/0x004ce50c/0x004ce516`.
- [UID:0000SA][g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md) remains a 4-byte `.data` singleton at `0x0067a7d4` with live xrefs at `0x00451adb`, `0x004c751b`, `0x004c7522`, `0x004c75fa`, `0x004c76ad`, `0x004c772a`, `0x004c7731`, `0x004ce320`, and `0x004ce520`.
- 2026-07-05 B004 UID00048M MCP recheck repairs the source signature for [UID:00048M][0x004c7610-0x004c7620.SimpleHelpPane2OnAccept](by-memory/0x004c7610-0x004c7620.SimpleHelpPane2OnAccept.md): `lookup_funcs` size `0x10`, exact function bytes `81 c1 5c ff ff ff e8 75 d0 07 00 b0 01 c2 0c 00`, `add ecx, 0FFFFFF5Ch` (`this - 0xa4`), call close helper `0x00544690`, `mov al, 1`, and `retn 0Ch`. The `this - 0xa4` adjustment plus constructor timer scheduling on `this+0xa4` and the `0x0061acec` slot in the `0x0061ace8` tertiary table make it a TimerHandler `OnTimer(int,int,int)` callback, not a `PaneEvent` accept handler. A wildcard-identical body at `0x004f5030` keeps final original spelling a confidence cap, not a code blocker.
- IDA still reports no direct code xrefs to constructor entry `0x004c74b0`; the live construction surface is the adjacent factory at `0x004c7680`, which is called from `0x0045213c` and by raw wrappers at `0x004c77fe` and `0x004c783b`.
- 2026-06-04 raw helper recheck confirms IDA has no function objects at `0x004c77e0`, `0x004c7810`, or `0x004c7850`. The first two bodies forward to `0x004c7680`; the third reads `g_pEventMan`, gets cursor position, offsets the stored anchor rectangle, checks emptiness, and calls the rectangle containment helper `0x004b7e80`.
- 2026-06-26 B009 implementation sync for [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md) updates the helper cluster from blank-C++ evidence to first-draft formal C++. Current MCP/static checks still show no modeled raw-start functions, no direct raw-start xrefs, and no VA/RVA/raw-offset pointer routes, but those are now confidence caps. The accepted source-facing predicate name is `SimpleHelpPane2::IsCursorInsideAnchorRect`; it treats an empty/invalid stored anchor as permissive true and otherwise tests `PointInRect(cursor.y, cursor.x, &screenAdjustedAnchorRect)`.
- 2026-06-27 B007 split implementation turns [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) into a non-emitting parent index; exact method children [UID:00048K][0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor](by-memory/0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor.md)-[UID:00048O][0x004c7670-0x004c7680.SimpleHelpPane2OnCancel](by-memory/0x004c7670-0x004c7680.SimpleHelpPane2OnCancel.md) now carry owner/emitter [UID:0000D7] and source-shaped formal C++ bodies.
- The constructor/destructor children preserve observed singleton publish/clear as implicit base lifetime, three-vtable install/rewrite evidence, `m_anchorRect` at `+0x224`, auto-hide scheduling, and the no-direct-xref caveat for constructor entry `0x004c74b0`. Exact event children preserve UID00048M `OnTimer` handled close semantics, UID00048N pointer/mouse anchor logic and always-false return, and UID00048O key/text close/false behavior.
- UID00048N uses accepted Event `m_type` at `+0x04`, y at `+0x08`, and x at `+0x0c`; left/right button down or cursor movement outside the anchor calls `ScheduleTimer(0,0,0,0)`. `0x005975e0` schedules through TimerMgr; owner-wide removal is separate `0x00597600`. Historical `CancelTimer`, `PaneEvent`, local `kPaneEvent*`, x-first, generic `HandleEvent`, and `OnCancel` interpretations are superseded.
- Source positions are constructor `10`, ordinary destructor `20`, `OnTimer` `30`, pointer/mouse `40`, and key/text `50`. The complete class closes before `[[CHILDREN]]`, so exact children remain non-duplicating sole body emitters.

## 2026-06-17 Scalar Destructor Wrapper Split

- B003 split [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md) and assigned the exact `0x004ce500-0x004ce55f` wrapper to [UID:0003YY][0x004ce500-0x004ce55f.SimpleHelpPane2ScalarDeletingDestructor](by-memory/0x004ce500-0x004ce55f.SimpleHelpPane2ScalarDeletingDestructor.md) at `87/92`, owner/emitter [UID:0000D7].
- Source-facing name is `virtual SimpleHelpPane2::~SimpleHelpPane2()`. The wrapper and `+0xa0/+0xa4` adjustor thunks are compiler ABI glue and formal C++ remains blank on the wrapper page.
- The wrapper validates `g_pSimpleHelpPane2` (`dword_67A7D4`) cleanup, primary vtable slot `0x0061ac6c`, secondary/tertiary vtable views `0x0061acb8/0x0061ace8`, and teardown through `HelpPane::~HelpPane`.

## 2026-06-21 Factory Source-Quality Sync

- B009 resolved [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md) as source-ready HelpPanes file-local factory code, best named `CreateSimpleHelpPane2` with `ShowSimpleHelpPane2` retained as a plausible command-style alias.
- Historical B009 draft used `const HelpPaneStyle *style` as a descriptive placeholder. The UID0003ZY source-closure pass supersedes that spelling with the existing concrete [UID:00005C][FontStyle](by-class/FontStyle.md) type while preserving the same wide-text, owner, coordinate, anchor, timeout, and alignment ABI.
- The singleton guard byte at `+0xf4` is source-drafted as `m_preventReplacement`. When set on the existing [UID:0000SA][g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md), the factory preserves the current pane; otherwise it deletes the old pane and constructs a new `SimpleHelpPane2`.
- The factory page, not this class index, owns the first-draft formal C++ body. The class page keeps the constructor/event/destructor/factory map and the caveat that final private field names and exact helper visibility are below final-audit certainty.

## 2026-06-26 Helper Source-Quality Sync

- B009 resolved [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md) as source-ready HelpPanes helper code. The helper page, not this class index, owns the first-draft formal C++ bodies.
- `CreateSimpleHelpPane2Forward` is a file-local adapter whose incoming coordinate parameters are `y, x`; it forwards to the canonical factory in `x, y` order. This preserves the observed stack push order at `0x004c77e0-0x004c7808` and supersedes older same-order wrapper wording.
- `CreateSimpleHelpPane2FromAnchorRect` computes `x = (left + right) / 2` and `y = top - 6` from the supplied anchor rectangle before calling the canonical factory.
- `SimpleHelpPane2::IsCursorInsideAnchorRect` is the current best source-facing name for the raw predicate at `0x004c7850-0x004c78db`. It uses `g_pEventMan` cursor state, the pane screen offset, a local screen-adjusted copy of `m_anchorRect`, `RectBounds::IsEmptyOrInvalid`, and `PointInRect`; an empty/invalid anchor returns true, meaning no anchor restriction is active.
- The complete class formal declares all accepted child methods and `IsCursorInsideAnchorRect`, then closes before `[[CHILDREN]]`. Constructor, destructor, callback, factory, and helper bodies remain emitted only from their exact by-memory pages.

## Direct Inheritance, RTTI, And Layout

- Primary complete-object locator `0x00648014`, hierarchy descriptor `0x00648028`, and eight-entry base array `0x00648038` identify `SimpleHelpPane2`, inherited HelpPane/GrafPort/LObject/EventHandler/TimerHandler ancestry, and direct empty `Singleton<SimpleHelpPane2>`.
- The Singleton type descriptor is `0x006764e0`; base descriptor `0x00648078` records nonvirtual PMD `mdisp=0x224`, `pdisp=-1`, `vdisp=0`. The self descriptor is `0x0064805c` with type descriptor `0x006764c0`.
- HelpPane inherited storage occupies `0x224` bytes. Empty-base optimization lets the direct Singleton base and first derived field share `+0x224`; constructor/helper uses identify the field as 16-byte `RectBounds m_anchorRect` spanning `+0x224-+0x233`.
- Factory allocation and scalar-wrapper guarded delete independently prove complete object size `0x234`. There is no source-authored padding field, explicit singleton member, secondary-vptr field, or tail array.
- Primary, EventHandler-view, and TimerHandler-view tables are `0x0061ac6c`, `0x0061acb8`, and `0x0061ace8`; secondary complete-object locators record offsets `+0xa0/+0xa4`. These facets are inherited through HelpPane, not repeated as direct source bases.

## Source, Compiler, And Linkage Separation

- Human source consists of this declaration plus exact child bodies UID00048K/L/M/N/O, file factory UID00016T, and helper bodies UID00022O. Vptr stores, adjusted `this`, Singleton publication/clear, base destruction, deleting flags, storage free, guarded size, RTTI, and raw table arrays remain compiler/base output.
- The primary vtable deletion slot routes to non-emitting UID0003YY. Adjustors at `0x004ce377/0x004ce382` subtract `0xa0/0xa4` before entering the wrapper; they are not methods declared here.
- `g_pSimpleHelpPane2` requires an external declaration because MiniMapDialog reads the same storage at `0x00451adb` outside the HelpPanes executable family. UID0000SA supplies the one external definition; UID0001OY remains its exact covered storage marker.
- Rejected alternatives are a comment-only class marker, manual singleton assignment/clear, file-static global, direct EventHandler/TimerHandler duplication, raw-layout padding, wrapper source method, MiniMap ownership, and broad parent emission.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `92` | Direct inheritance, exact `0x234` layout, complete declaration, external global declaration, five ordered human children, private helper/member, factory/helper route, and compiler/no-code products are all implementation-ready and emitted without duplication. |
| Confidence `94` | Fresh RTTI PMDs, complete-object locators, vtables, allocation/guard size, lifecycle xrefs, exact child bodies, Event/Timer interfaces, and same-family comparators agree. Exact original access/header/helper/style spellings and no direct constructor xref remain lexical caps below 95. |

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md)
- [UID:00048K][0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor](by-memory/0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor.md)
- [UID:00048L][0x004c75e0-0x004c7609.SimpleHelpPane2Destructor](by-memory/0x004c75e0-0x004c7609.SimpleHelpPane2Destructor.md)
- [UID:00048M][0x004c7610-0x004c7620.SimpleHelpPane2OnAccept](by-memory/0x004c7610-0x004c7620.SimpleHelpPane2OnAccept.md)
- [UID:00048N][0x004c7620-0x004c7668.SimpleHelpPane2HandleEvent](by-memory/0x004c7620-0x004c7668.SimpleHelpPane2HandleEvent.md)
- [UID:00048O][0x004c7670-0x004c7680.SimpleHelpPane2OnCancel](by-memory/0x004c7670-0x004c7680.SimpleHelpPane2OnCancel.md)
- [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md)
- [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md)
- [UID:0000SA][g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md)
- [UID:000063][HelpPane](by-class/HelpPane.md)
- [UID:0003YY][0x004ce500-0x004ce55f.SimpleHelpPane2ScalarDeletingDestructor](by-memory/0x004ce500-0x004ce55f.SimpleHelpPane2ScalarDeletingDestructor.md)

## Changes

- 2026-07-21 B004 UID0003ZY accepted callback: preserved `92/94`, owner/emitter UID0000JU, position `20`, full class/method/layout/singleton union, and all unrelated formals; changed only the constructor's stale `const HelpPaneStyle *` placeholder to the evidence-backed `const FontStyle *` type and historicalized the old placeholder rationale.

- 2026-07-14 B003 UID00048L implementation callback:
  - Raised `88/90 -> 92/94`, set source position `20`, retained UID0000JU owner/emitter, and replaced the historical comment-only marker with the complete `HelpPane` plus `Singleton<SimpleHelpPane2>` declaration.
  - Added exact RTTI/BCD/PMD/COL/vtable/EBO/`0x234` layout, one-field/access, ordered-child, global-linkage, source/compiler separation, rejected-alternative, and score evidence. Singleton publication/clear is now implicit base lifetime; UID0003YY is compiler-only.
  - Preserved all accepted factory/helper, EventHandler/TimerHandler, anchor behavior, no-direct-xref, historical slug, source-family, and unrelated HelpPanes detail.
- 2026-07-14 B002 UID00048I implementation callback:
  - Preserved `88/90`, [UID:0000JU][HelpPanes](by-file/HelpPanes.md) owner/emitter routing, factory/layout/singleton evidence, accepted UID00048M `OnTimer`, and the no-standalone marker plus `[[CHILDREN]]`.
  - Corrected UID00048N/O to EventHandler pointer/mouse and key/text roles, positions `40/50`, y/x payload and anchor semantics, schedule-versus-remove behavior, always-false/close outcomes, source placement, and historicalized generic/cancel aliases without duplicating child source.

- 2026-07-05 B004 [UID:00048M][0x004c7610-0x004c7620.SimpleHelpPane2OnAccept](by-memory/0x004c7610-0x004c7620.SimpleHelpPane2OnAccept.md) source-signature repair:
  - Updated the class method map and evidence so UID00048M is the `SimpleHelpPane2::OnTimer(int,int,int)` TimerHandler-facet timeout callback, with the path slug retained as historical.
  - Preserved owner/emitter [UID:0000D7], the HelpPanes route, class completion `88`, and the no-standalone class formal C++ marker plus `[[CHILDREN]]`.
  - Raised confidence from `88` to `90` because current MCP evidence resolves the stale `PaneEvent` accept inference while preserving the no-direct-constructor-xref, exact source-split, and callback-spelling confidence caps.

- 2026-06-27 B007 [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) split implementation:
  - Before: completion/confidence were `86/86`, and this class page still referenced the aggregate range rather than exact method children.
  - After: completion/confidence are `88/88`; exact children [UID:00048K][0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor](by-memory/0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor.md)-[UID:00048O][0x004c7670-0x004c7680.SimpleHelpPane2OnCancel](by-memory/0x004c7670-0x004c7680.SimpleHelpPane2OnCancel.md) carry method-level formal C++ under owner/emitter [UID:0000D7].
  - Evidence: accepted B007 source-quality report and validator-applied child pages preserve `m_anchorRect` at `+0x224`, singleton lifecycle, event/vtable references, timer-cancel and close-handler behavior, and the no-direct-xref constructor caveat.

- 2026-06-30 B004 HelpPanes empty-emitter first batch:
  - Added the accepted no-standalone class marker plus `[[CHILDREN]]` insertion point to the formal block.
  - Kept exact method children [UID:00048K][0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor](by-memory/0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor.md)-[UID:00048O][0x004c7670-0x004c7680.SimpleHelpPane2OnCancel](by-memory/0x004c7670-0x004c7680.SimpleHelpPane2OnCancel.md), factory [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md), helper cluster [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md), and scalar wrapper [UID:0003YY][0x004ce500-0x004ce55f.SimpleHelpPane2ScalarDeletingDestructor](by-memory/0x004ce500-0x004ce55f.SimpleHelpPane2ScalarDeletingDestructor.md) as the body/helper emitters so this class index does not duplicate child output.

- 2026-06-26 B009 helper source-quality sync:
  - Updated the [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md) row and evidence to reflect first-draft helper C++ readiness.
  - Added the source-facing predicate direction `SimpleHelpPane2::IsCursorInsideAnchorRect`, including the true result for empty/invalid stored anchors and the screen-adjusted point-in-rect test.
  - Preserved this class page's blank formal C++ policy because exact method/helper bodies belong on by-memory child pages.
- 2026-06-21 B009 factory source-quality sync:
  - Added the source-ready `CreateSimpleHelpPane2` signature direction, `m_preventReplacement` field-name inference for byte `+0xf4`, pointer-return rationale, and wide-text/style argument roles from [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md).
  - At that time the class page's formal C++ stayed blank because the exact method bodies remained split across child by-memory pages and the factory body emitted from [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md). The 2026-06-30 B004 entry supersedes that blank route with a no-standalone marker plus `[[CHILDREN]]`.
- 2026-06-04 live IDA recheck:
  - Before: completion/confidence were `82/76`, `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, and the page did not document the ordinary teardown at `0x004c75e0`.
  - Changed to: completion `86`, confidence `86`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JU`.
  - Evidence: live IDA MCP confirmed the full method map, the ordinary destructor body at `0x004c75e0-0x004c7609`, three `SimpleHelpPane2` vtable views at `0x0061ac6c`, `0x0061acb8`, and `0x0061ace8`, lifecycle vtable writes, all nine singleton xrefs to `0x0067a7d4`, factory callers at `0x0045213c`, `0x004c77fe`, and `0x004c783b`, and the raw helper bodies following the factory.
- 2026-06-17 B003 destructor-wrapper split sync:
  - Added exact scalar wrapper child [UID:0003YY][0x004ce500-0x004ce55f.SimpleHelpPane2ScalarDeletingDestructor](by-memory/0x004ce500-0x004ce55f.SimpleHelpPane2ScalarDeletingDestructor.md) and preserved the blank formal C++ policy because source is the ordinary virtual destructor.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Evidence: the page documents inheritance, singleton, anchor/timer behavior, constructor, input handlers, factory, raw helper island, scalar destructor, and IDA xref caveats; confidence is capped because the constructor has no current direct xrefs.
