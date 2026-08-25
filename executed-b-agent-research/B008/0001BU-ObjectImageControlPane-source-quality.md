** TARGET-REPORT-UID:0001BU **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001BU ObjectImageControlPane Source-Quality Report

Target: `source-3/project-documentation/by-memory/0x00520540-0x00520816.ObjectImageControlPane.md`

Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B008/research/0001BU-ObjectImageControlPane-source-quality.md`

Date: 2026-06-19

Agent: B008

Mode: B-agent report first. No target/support by-* documentation edits performed. No `by-memory/-coverage-report.md` edit performed. Existing B008 reports, including `000191-ListConstructor-source-quality.md`, were preserved.

## Finalized Report / Current Recommendation

- Current recommendation: keep the source-file route under [UID:0000M3] `ObjectImageControlPane.cpp`, but change the target's direct semantic owner/emitter from the file to [UID:00009O] `ObjectImageControlPane` if the supervisor accepts a metadata cleanup during implementation.
- Final disposition: source-authored, reconstructable class-method cluster containing the plain `ObjectImageControlPane` constructor and paint virtual only.
- Required action after supervisor review: update target evidence, scores, source signatures, descriptor/field terminology, constructor subrange endpoint, C++ block, and support docs; do not emit scalar deleting destructor/thunk/rdata bytes as handwritten source.
- Recommended target score: `COMPLETION:90`, `CONFIDENCE:91`.
- Implementation readiness: first-draft C++ is ready for the constructor and paint body using the source-facing names below. Exact image-library parameter names remain descriptive support aliases, but they are no longer a blocker for first-draft target code.

## Target

- Target UID: `0001BU`
- Target path: `source-3/project-documentation/by-memory/0x00520540-0x00520816.ObjectImageControlPane.md`
- Current scores and parent state: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000M3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000M3`
- Current source route: [UID:0001BU] -> [UID:0000M3] `ObjectImageControlPane` file -> `auto-generated/NexusTK/ui/controls/ObjectImageControlPane.cpp`
- Stronger semantic owner route now recommended: [UID:0001BU] -> [UID:00009O] `ObjectImageControlPane` class -> [UID:0000M3] `ObjectImageControlPane` file.
- Current generated output: `auto-generated/NexusTK/ui/controls/ObjectImageControlPane.cpp` contains only empty emitter markers for the file, `ObjectImageControlPane`, `ObjectImageButtonPane`, this target, and `ObjectImageButtonPaneCore`.

## Executive Recommendation

The target is not a passive "descriptor unresolved" item anymore. The constructor and paint source shape can be written at first-draft quality with these names:

```cpp
ObjectImageControlPane::ObjectImageControlPane(const ObjectStatusBlob *objectStatus,
                                               const RectBounds *bounds);

void ObjectImageControlPane::OnPaint();
```

Use [UID:0000M6]/[UID:00009S]/[UID:000179] `ObjectStatusBlob` as the descriptor type. Do not introduce a separate `ObjectImageDescriptor` source type unless a later header/declaration pass wants a typedef or alias for UI readability. The object-image control copies the same 68-byte packet/render status blob parsed by map/look/head-selection code.

The member copied to `this + 0x108..0x14b` is best named `m_objectStatus` or `m_imageStatus`:

```cpp
ObjectStatusBlob m_objectStatus; // offset +0x108, size 0x44 / decimal 68
```

The byte at `this + 0x130` is not an independent pane render-state field. It is `m_objectStatus + 0x28`, the same `ObjectStatusBlob::m_displayStatusByte` / `defaultByte` documented in the parser and HeadSelect pages. The constructor writes `0x50` to that byte before copying the 68-byte incoming descriptor; the copy includes offset `+0x28`, so the write is a pre-copy default/defensive store and is overwritten for ordinary non-aliasing constructor arguments.

Recommended target metadata:

```text
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00009O | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00009O | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

If the supervisor prefers to avoid owner/emitter churn in this callback, keeping `CANONICAL_OWNER:0000M3` and `EMITTER_UIDS:0000M3` is still valid because the file page is the accepted source route. The class route is more precise by current by-structure semantics for a class method cluster.

## Supervisor Active Recheck

- The supervisor assigned a report-only B-agent source-quality pass for [UID:0001BU].
- The assigned target itself does not need split repair. The source-bearing constructor and paint method already fit the target range `0x00520540-0x00520816`.
- A small subrange correction is needed inside the target docs: the constructor half-open range is `0x00520540-0x005205b5`, not `0x00520540-0x005205b4`. The final instruction is `ret 8` at `0x005205b2`, whose three bytes end at `0x005205b5`; padding begins at `0x005205b5`.
- The non-contiguous adjustor thunks at `0x00520afd` and `0x00520b08`, scalar deleting destructor at `0x00520ca0`, and object-image vtables in [UID:00025U] are support evidence, not handwritten source for this target's C++ block.

## Inference Research Guidance Check

Applied guidance:

- `by-structure.md`: source-quality questions must be researched before code entry; 85/85 is not a stop condition.
- `by-structure.md`: final-output C++ is allowed when a reconstructable item has a nonblank emitter route and `(COMPLETION + CONFIDENCE) / 2 > 85`. This target qualifies after the recommended score update and already has a valid source route.
- `by-structure.md`: by-memory C++ must stay limited to the target range. This target should emit only the constructor and `OnPaint`, not destructor thunks, scalar delete glue, or vtable/rdata bytes.
- `inference_research.md`: original names are probabilistic without debug metadata; use caller patterns, object layout, sibling docs, parser layout, globals, and negative evidence to choose descriptive source names.

Evidence type separation:

- Direct raw fact: local PE section parsing and Capstone disassembly of the constructor, paint method, button constructor, destructor thunks, scalar deleting destructor, boundary padding, and 28 constructor call sites.
- Documentation evidence: current target/class/file pages, sibling `ObjectImageButtonPane` pages, `ObjectStatusBlob` parser/class/file pages, B001 HeadSelect report, B002 MapPane/ObjectStatusBlob report, image-library global/class pages, `GrafPort`/`EPFTileContext`/`SurfaceRenderCallbackTable` support docs, and proposed source tree.
- Inference: exact source member spelling (`m_objectStatus` versus `m_imageStatus`), exact enum labels for status kind, and source-style wrappers/names for image-library render flags.

IDA MCP note: the local endpoint `http://127.0.0.1:13337/mcp` was unavailable in this session (`Unable to connect to the remote server`). This report therefore uses the existing live IDA-backed project docs plus fresh direct PE/Capstone checks. Confidence is kept below final-audit level for that reason and because some image-library parameter names remain descriptive.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best direction | Rejected alternatives / impact |
| --- | --- | --- | --- |
| Descriptor type | Target copies 68 bytes; `ObjectStatusBlob` docs define a 68-byte shared appearance/status packet; HeadSelect stores `ObjectStatusBlob m_previewObject` at `+0x278` and passes it to this constructor; MapPane/ObjectStatusBlob B002 report resolves the same field aliases | Use `const ObjectStatusBlob *objectStatus` and member `ObjectStatusBlob m_objectStatus` / `m_imageStatus` | Do not leave `ObjectImageDescriptor` as an unresolved raw name. A UI alias can exist later, but the strongest documented real layout owner is `ObjectStatusBlob`. Do not use `MenuCommandRecord` or menu-local record names. |
| Constructor signature and argument order | Raw constructor uses `[ebp+8]` as source descriptor, `[ebp+0xc]` as bounds pointer; all 28 call sites push bounds first then descriptor; button constructor preserves the same order; base call passes `ControlPane(8, bounds)` | `ObjectImageControlPane::ObjectImageControlPane(const ObjectStatusBlob *objectStatus, const RectBounds *bounds)` | `RectBounds` first is contradicted by raw pushes. `void *` or `char *` descriptor is stale. `const RectBounds&` is possible at source level, but existing `ControlPane` and sibling control docs use pointer-style bounds. |
| Base constructor | Raw `0x00520545-0x0052054f` pushes `[ebp+0xc]`, then `8`, then calls `0x004949e0`; `ControlPaneConstructor` documents `ControlPane::ControlPane(unsigned char controlType, const RectBounds *bounds)` | Source initializer/base call is `ControlPane(8, bounds)` | Do not call `Pane` directly in target C++; `Pane` construction is inside `ControlPane`. |
| Constructor vtable writes | Raw writes vtables `0x0061f6c0`, `0x0061f728`, `0x0061f758` at `+0/+0xa0/+0xa4`; read-only data support page records these heads | Compiler-generated vptr installation from class definition, not handwritten C++ | Do not emit vtable stores in source. Keep them as evidence for class layout and vtable support docs. |
| `+0x130` byte | Constructor writes `0x50` at `this+0x130`, then copies descriptor bytes to `this+0x108..0x14b`, including `+0x130`; ObjectStatusBlob parser docs identify descriptor offset `+40` (`0x28`) as display/default byte; HeadSelect draft sets `m_previewObject.defaultByte = 0x50` | `this+0x130` is `m_objectStatus.m_displayStatusByte` / `defaultByte`, not a separate pane field. Source draft can show the pre-copy store before assignment to match raw order. | Reject independent `m_renderState` unless later code proves a separate overlay. The target should explicitly explain the pre-copy write is overwritten for non-aliasing descriptors. |
| Descriptor copy layout | Raw copy uses four `movups` at offsets `+0x108/+0x118/+0x128/+0x138` and final dword at `+0x148`, totaling `0x44` / decimal 68 bytes | `m_objectStatus = *objectStatus;` is the right source-level shape | Do not emit `memcpy` unless the class declaration cannot support ordinary POD assignment. Do not split fields into separate UI-owned members. |
| Object size and descriptor end | Control scalar deleting destructor guarded-size path passes `0x14c`; descriptor copy last dword ends at `+0x14c`; button scalar deleting destructor uses size `0x150` and button constructor writes `+0x14c` highlight byte | Plain control size is `0x14c`; button adds at least one byte at `+0x14c` | Reject treating `+0x14c` as plain-control state. It belongs to `ObjectImageButtonPane`. |
| Paint virtual signature | Raw paint uses only `ecx=this`, no stack args, and returns with plain `ret`; vtable ref at `0x0061f704`; class docs already call it `OnPaint` | `void ObjectImageControlPane::OnPaint()` | Reject generated/raw names and signatures with event args. Event handlers are separate in button/key code. |
| Paint setup helpers | Raw calls `EPFTileContext::InitTileContext` (`0x00457a60`) on stack local, `GrafPort::SetDrawColor(0)` (`0x004b9660`), and callback slot `0x0069b3fc(this, &m_bounds)`; support docs identify these roles | Use descriptive names: `EPFTileContext::InitTileContext`, `SetDrawColor(0)`, and `SurfaceRenderCallbackTable` slot `PreparePaneSurface` / `PreparePaneRenderRegion` | Reject old `g_pfnLockSurface` as source-facing here; support docs say it is a callsite-biased alias over `SurfaceRenderCallbackTable` slot `dword_69B3FC`. |
| Image-library globals | Global pages identify `g_pNewHumanImageLib` at `0x0067a760`, `g_pMonsterImageLib` at `0x0069b440`, and `g_pItemObjImageLib` at `0x0067a758` | Use those exact global names in target docs and C++ draft | Reject raw `dword_67A760`, `dword_69B440`, `dword_67A758` except as search aliases. |
| Human paint path | Raw branch kind `0` calls `NewHumanImageLib::CalculateBounds` (`0x004e09e0`) then `NewHumanImageLib::Draw` (`0x004e06a0`); HeadSelect writes `headIndex` at descriptor `+4` and `headDrawOffset` at `+6` | Status kind `0` is full human/avatar appearance; draft enum name `ObjectStatusBlob::HumanObject` / `HumanAppearance` | Previous `FullLivingObject` wording is useful for MapPane but too broad for this renderer. Document as human/avatar for this target. |
| Monster paint path | Raw branch kind `1` calls `MonsterImageLib::ComputeRenderBounds` (`0x004db5c0`) then `RenderMonsterImage` (`0x004db3b0`) | Status kind `1` is monster appearance in this renderer; draft enum alias `MonsterObject` / `MonsterAppearance` | Do not call it merely "compact living" in this target; image dispatch proves the concrete library is monster. |
| Item/EPF paint path | Raw branch kind `2` reads word descriptor `+4` (`this+0x10c`) and byte descriptor `+6` (`this+0x10e`), calls `GetItemGlyphBounds` (`0x004df460`) and `ItemObjImageLib::DrawItemImage` (`0x004dee50`) | Status kind `2` is item/EPF object; `+4` is `m_appearanceId` / item id, `+6` is variant/palette byte | Do not call it NPC-only. Current docs' "EPF/item/NPC" is acceptable as a broad resource-family label, but item-image library evidence is strongest. |
| Centering math | Raw repeats `((bounds.left + bounds.right) / 2) - ((image.right - image.left) / 2)` and same for y; destination right/bottom preserve measured width/height | Source draft should compute a centered `RectBounds destBounds` inside the pane bounds | Do not introduce a runtime call to a rectangle-centering helper; raw has no callee. A source-level inline/private helper is possible but not evidenced. |
| Button subclass relationship | Raw button ctor calls base at `0x00520830`, installs button vtables, clears `+0x102`, `+0xff`, `+0x14c`; HeadSelect is the one direct external constructor user | Keep `ObjectImageButtonPane` in the same source family or adjacent file; inherit descriptor member from base | Reject generic `SpecializedButtonPanes` as direct owner. Keep it as historical cross-reference only. |
| Merchant/menu read-only vtables | [UID:00025U] records object-image vtables at `0x0061f6c0/0x0061f728/0x0061f758` and button vtables nearby | Source-declared/generated-binary support evidence; no handwritten code bytes | Do not emit rdata aggregate as code. Class declarations and virtual methods should regenerate vtables. |
| Scalar deleting destructor/thunks | Raw thunks subtract `0xa0`/`0xa4` then jump to `0x00520ca0`; scalar dtor calls `0x00544580`, conditionally `0x004f4ac0`, or guard-sized delete `0x0041b6a0` with size `0x14c` | Compiler-generated wrapper/thunks. Source declaration should be `virtual ~ObjectImageControlPane()` if needed; formal target C++ remains constructor/paint only. | Do not port deleting destructor C++ into this target. Do not treat generated `TextButtonExControlPane` labels as inheritance proof. |
| Source placement | Proposed source tree, by-file page, broad constructor fanout, and sibling relationship all support `NexusTK/ui/controls/ObjectImageControlPane.cpp` | Keep file route [UID:0000M3] and class route [UID:00009O] | Reject feature-dialog ownership (`HeadSelectDialog`, menu dialogs, message dialogs) because they are consumers only. |
| First-draft C++ readiness | Target is reconstructable, has an emitter route, average score after recommendation is above 85, exact method boundaries are known, and source-level descriptor type is resolved | Populate first-draft constructor and paint C++ after supervisor callback | Keep score below 95 because exact original enum/member spellings and render-library parameter names remain descriptive, and live IDA MCP was unavailable in this session. |

## Raw PE / Capstone Facts

Executable checked:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
```

Offset/size conversions used in this report were rechecked with `tools/int_convert.py`: `0x44` is decimal `68`, `0x108` is decimal `264`, `0x130` is decimal `304`, `0x14c` is decimal `332`, `0x150` is decimal `336`, `0x28` is decimal `40`, `0xa0` is decimal `160`, and `0xa4` is decimal `164` (Verified with int_convert.py).

Constructor `0x00520540-0x005205b5`:

```asm
00520545  push dword ptr [ebp + 0xc]    ; bounds
0052054a  push 8                         ; ControlPane type
0052054f  call 0x004949e0                ; ControlPane::ControlPane
00520554  mov eax, dword ptr [ebp + 8]   ; descriptor
00520557  mov dword ptr [esi], 0x61f6c0
0052055d  mov dword ptr [esi + 0xa0], 0x61f728
00520567  mov dword ptr [esi + 0xa4], 0x61f758
00520571  mov byte ptr [esi + 0x130], 0x50
00520578  movups xmm0, xmmword ptr [eax]
0052057b  movups xmmword ptr [esi + 0x108], xmm0
00520582  movups xmm0, xmmword ptr [eax + 0x10]
00520586  movups xmmword ptr [esi + 0x118], xmm0
0052058d  movups xmm0, xmmword ptr [eax + 0x20]
00520591  movups xmmword ptr [esi + 0x128], xmm0
00520598  movups xmm0, xmmword ptr [eax + 0x30]
0052059c  movups xmmword ptr [esi + 0x138], xmm0
005205a3  mov eax, dword ptr [eax + 0x40]
005205a6  mov dword ptr [esi + 0x148], eax
005205b2  ret 8
```

Boundary bytes:

```text
0x005205b5-0x005205c0: cc cc cc cc cc cc cc cc cc cc cc
0x00520816-0x00520820: cc cc cc cc cc cc cc cc cc cc
```

Paint `0x005205c0-0x00520816`:

- Prologue reserves `0x48` bytes and stores the security cookie.
- Calls `0x00457a60` on stack local `[ebp-0x3c]`.
- Calls `0x004b9660` with argument `0`, setting draw color at the inherited GrafPort/control state.
- Calls callback slot `0x0069b3fc(this, this + 0x44)`.
- Branches on dword `this + 0x108`:
  - `0`: `g_pNewHumanImageLib` at `0x0067a760`, bounds `0x004e09e0`, draw `0x004e06a0`.
  - `1`: `g_pMonsterImageLib` at `0x0069b440`, bounds `0x004db5c0`, draw `0x004db3b0`.
  - `2`: `g_pItemObjImageLib` at `0x0067a758`, bounds `0x004df460`, draw `0x004dee50`, item id word `this+0x10c`, variant byte `this+0x10e`.
- Unknown/default and item branches call `EPFTileContext::ReleaseBuffers` at `0x00458500` before the common epilogue. Human and monster branches return early after drawing.

Constructor call scan:

```text
Direct calls to 0x00520540: 28
0x0051832d 0x005188bc 0x00518c20 0x00519c94 0x0051a134 0x0051aaae
0x0051bcaa 0x0051c1d6 0x0051ceae 0x0051d3eb 0x0051df07 0x0051e3a4
0x0051ef56 0x00520830 0x0054d3ad 0x0054d9c9 0x0054e130 0x0054e752
0x0054f02c 0x0054f783 0x0055023f 0x005509a8 0x005510c9 0x0055117b
0x005519c0 0x00551ed3 0x00552867 0x00553020
```

Every visible call pattern pushes a `RectBounds` pointer first and the descriptor pointer second, then calls with `ecx` as the allocated pane object. HeadSelect calls pass `this+0x278` as the descriptor (`ObjectStatusBlob m_previewObject`), and the button constructor at `0x00520830` forwards its own `[ebp+8]` descriptor and `[ebp+0xc]` bounds unchanged.

Button constructor support:

```asm
00520825  push dword ptr [ebp + 0xc]
0052082a  push dword ptr [ebp + 8]
00520830  call 0x00520540
00520835  mov dword ptr [esi], 0x61f764
0052083d  mov dword ptr [esi + 0xa0], 0x61f7cc
00520847  mov dword ptr [esi + 0xa4], 0x61f7fc
00520851  mov byte ptr [esi + 0x102], 0
00520858  mov word ptr [esi + 0xff], 0x101
00520861  mov byte ptr [esi + 0x14c], 0
0052086c  ret 8
```

Control destructor/thunk support outside the target:

```asm
00520afd  sub ecx, 0xa0
00520b03  jmp 0x00520ca0
00520b08  sub ecx, 0xa4
00520b0e  jmp 0x00520ca0

00520ca6  call 0x00544580
00520cae  test al, 1
00520cb6  call 0x004f4ac0
00520cc6  push 0x14c
00520ccc  call 0x0041b6a0
00520cd8  ret 4
```

The scalar deleting destructor proves a plain-control guarded size of `0x14c`; the button scalar deleting destructor uses `0x150`, matching the subclass byte at `+0x14c`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00520540-0x005205b5` | [UID:0001BU] target subrange | `ObjectImageControlPane` constructor | TRUE | recommend [UID:00009O] | included in target `90/91` | first-draft C++ ready |
| `0x005205b5-0x005205c0` | padding | alignment before paint | FALSE/padding | target neighborhood | 100 | already covered by ignored/padding row context |
| `0x005205c0-0x00520816` | [UID:0001BU] target subrange | `ObjectImageControlPane::OnPaint()` | TRUE | recommend [UID:00009O] | included in target `90/91` | first-draft C++ ready |
| `0x00520816-0x00520820` | padding | alignment before button constructor | FALSE/padding | target/button neighborhood | 100 | already covered by ignored/padding row context |
| `0x00520820-0x00520a90` | [UID:0001BV] `ObjectImageButtonPaneCore` | button subclass source-bearing methods | TRUE | [UID:0000M3], support should consider [UID:00009N] | current `85/88` | not edited; descriptor support update recommended |
| `0x00520afd-0x00520b13` | control adjustor thunks | compiler-generated destructor this-adjustors | FALSE/ignored | class vtable support | not target | no C++ emission |
| `0x00520ca0-0x00520cdb` | control scalar deleting destructor | compiler-generated scalar delete wrapper | FALSE/ignored or generated support | class vtable support | not target | no handwritten C++ emission |
| `0x0061f6c0/0x0061f728/0x0061f758` | [UID:00025U] subrange | ObjectImageControlPane vtables | source-declared/generated-binary | [UID:00009O]/[UID:0000M3] | support | declarations should regenerate |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0051832d` .. `0x0051ef56` | repeated menu/dialog constructor calls | Broad menu/dialog fanout using local descriptor and bounds records. Confirms reusable UI control, not a one-dialog helper. |
| `0x00520830` | `ObjectImageButtonPane` constructor | Subclass forwards descriptor and bounds to base, then installs button vtables and clears highlight state. |
| `0x005510c9`, `0x0055117b`, `0x005519c0`, `0x00551ed3` | HeadSelect preview/button paths | Pass `ObjectStatusBlob m_previewObject` at object `+0x278` to preview and buttons. Strongest descriptor-type evidence. |
| `0x005205c0` callees | `0x00457a60`, `0x004b9660`, `0x0069b3fc`, `0x004e09e0`, `0x004e06a0`, `0x004db5c0`, `0x004db3b0`, `0x004df460`, `0x004dee50`, `0x00458500`, security cookie check | Paint setup, dispatch, centered rendering, and cleanup. |
| `0x00520afd`, `0x00520b08` | thunks to `0x00520ca0` | Secondary/tertiary vtable destructor adjustors for `+0xa0` and `+0xa4` subobjects. |
| `0x00520ca0` | scalar deleting destructor support | Calls shared pane-base teardown and optional delete; support evidence only. |

## Documentation Evidence And Current Status

Existing docs that support the conclusion:

- [UID:0001BU] target already documents constructor and paint behavior, vtable writes, descriptor copy, human/monster/item paint dispatch, 28 constructor callers, and destructor/thunk support.
- [UID:00009O] class page records `ObjectImageControlPane` as a `ControlPane`-derived preview widget with constructor, `OnPaint`, destructor/thunks, vtable support, and broad caller fanout.
- [UID:0000M3] file page places the reusable preview and button subclass in `ui/controls/ObjectImageControlPane.cpp`.
- [UID:0001BV] and [UID:00009N] prove the button subclass directly calls this constructor and shares the source family.
- [UID:00025U] records the object-image vtables inside merchant/menu read-only data and classifies the rdata neighborhood as source-declared/generated-binary support, not method source.
- [UID:00009S]/[UID:000179] `ObjectStatusBlob` docs define the 68-byte parser layout and field aliases.
- B001 executed `HeadSelectDialogCore` report and current HeadSelect docs use `ObjectStatusBlob m_previewObject`, pass it to this constructor, and write `headIndex`/`headDrawOffset` subfields at descriptor offsets `+4/+6`.
- B002 executed MapPane/ObjectStatusBlob report resolves `+0` as status/object kind, `+4` as appearance/item id, `+6` as compact status/palette/variant, and `+40` as display/default byte.
- Image-library support docs identify the exact globals and method roles: `g_pNewHumanImageLib`, `g_pMonsterImageLib`, `g_pItemObjImageLib`, `NewHumanImageLib::CalculateBounds`/`Draw`, `MonsterImageLib::ComputeRenderBounds`/`RenderMonsterImage`, `GetItemGlyphBounds`, and `ItemObjImageLib::DrawItemImage`.

Existing docs that are stale, incomplete, or need implementation follow-up:

- Target and class/file docs still state or imply the constructor subrange ends at `0x005205b4`; use half-open `0x00520540-0x005205b5` for the constructor body and padding `0x005205b5-0x005205c0`.
- Target C++ is blank due "descriptor fields/declarations unresolved"; this is now stale. The descriptor type and first-draft field aliases are strong enough for C++ entry under the active gate.
- Target docs should stop describing `this+0x130` as a separate render-state byte without the overwrite caveat. It is descriptor offset `+0x28`.
- Target docs should replace raw globals with canonical names: `g_pNewHumanImageLib`, `g_pMonsterImageLib`, and `g_pItemObjImageLib`.
- `ObjectStatusBlob` support docs should add an object-image-consumer note that status kind `0/1/2` drives `HumanObject`/`MonsterObject`/`ItemObject` rendering. This reconciles with MapPane wording where `0` and `1` are both living-object branches.
- `ObjectImageButtonPaneCore` docs should use the same descriptor type/signature direction for its constructor: `ObjectImageButtonPane(const ObjectStatusBlob *objectStatus, const RectBounds *bounds)`.

## Ranked Ownership Analysis

### 1. [UID:00009O] `ObjectImageControlPane` class, emitted through [UID:0000M3] `ObjectImageControlPane.cpp`

- Evidence for: target contains class constructor and paint virtual only; class page is `85/86`; by-file route is accepted; vtables/class docs support direct class semantics; source C++ belongs inside class method definitions.
- Evidence against: current target metadata uses file owner/emitter; the project has several older file-level method-cluster routes for this source family.
- Decision: best semantic direct owner. Recommend changing `CANONICAL_OWNER` and `EMITTER_UIDS` to `00009O` if implementation scope allows.

### 2. [UID:0000M3] `ObjectImageControlPane` file

- Evidence for: current metadata route; file page is `86/86`; proposed source tree includes `ui/controls/ObjectImageControlPane.cpp`; broad source family includes both preview and button subclass.
- Evidence against: file is one level above the class methods, so it is less precise than [UID:00009O].
- Decision: keep as source-file parent and acceptable fallback owner/emitter if supervisor avoids owner churn.

### 3. [UID:00009N] / [UID:0001BV] `ObjectImageButtonPane`

- Evidence for: direct subclass call at `0x00520830`, shared descriptor renderer, adjacent source-bearing range.
- Evidence against: button derives from and consumes the base constructor/paint logic; it does not own the plain control body.
- Decision: support/sibling only. Use descriptor findings to update button docs later.

### 4. HeadSelectDialog, menu dialogs, message dialogs, item/spell dialogs

- Evidence for: many direct callers, especially HeadSelect creating preview and buttons.
- Evidence against: all are consumers; constructor fanout is broad across independent features; source tree and class/file docs classify this as reusable UI control infrastructure.
- Decision: reject feature-dialog ownership.

### 5. Render image libraries (`NewHumanImageLib`, `MonsterImageLib`, `ItemObjImageLib`)

- Evidence for: paint delegates to them.
- Evidence against: they own rendering resources and methods, not the UI control class. The control simply dispatches through their public/singleton APIs.
- Decision: reject ownership; keep as dependency/support pages.

## Negative Evidence Summary

- No target byte requires a split into another source owner. Constructor and paint are both plain `ObjectImageControlPane` methods.
- No evidence supports `ObjectImageDescriptor` as a separate source class; the 68-byte size and caller data point to `ObjectStatusBlob`.
- No evidence supports making `+0x130` a separate post-copy control field; descriptor copy overwrites it.
- No evidence supports feature-dialog ownership despite broad caller fanout.
- No handwritten source should be produced for the vtable writes, adjustor thunks, scalar deleting destructor wrapper, or rdata vtables. They are class-layout/compiler-generated consequences.
- Existing generated/old labels such as raw `dword_*`, `sub_*`, and `g_pfnLockSurface` are search aliases or callsite-biased support names, not final source names for this target.

## Recommended Exact Target Doc Changes

Do not apply until a supervisor sends an implementation callback.

### 1. Metadata

Preferred metadata replacement:

```text
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00009O | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00009O | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Fallback if supervisor wants no owner/emitter movement in this callback:

```text
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000M3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### 2. Status Addendum

Add or replace target status text with:

```markdown
## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: source-authored `ObjectImageControlPane` constructor and paint virtual.
- Exact constructor subrange: `0x00520540-0x005205b5` half-open.
- Exact paint subrange: `0x005205c0-0x00520816` half-open.
- Source-facing constructor signature: `ObjectImageControlPane::ObjectImageControlPane(const ObjectStatusBlob *objectStatus, const RectBounds *bounds)`.
- Source-facing paint signature: `void ObjectImageControlPane::OnPaint()`.
- Preferred direct owner: [UID:00009O][ObjectImageControlPane](by-class/ObjectImageControlPane.md), routed through [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) / `NexusTK/ui/controls/ObjectImageControlPane.cpp`.
- Rebuild handling: source-authored constructor and paint body. Constructor vtable stores, read-only vtables, adjustor thunks, and scalar deleting destructor wrappers are compiler-generated/source-declared support and should not be ported as handwritten target code.
```

### 3. Descriptor / Field Addendum

Recommended text:

```markdown
## Descriptor And Field Model

The descriptor copied by the constructor is the shared 68-byte [UID:0000M6][ObjectStatusBlob](by-file/ObjectStatusBlob.md), not a menu-local record. The control stores it at `this + 0x108..0x14b`; use `ObjectStatusBlob m_objectStatus` or `m_imageStatus` as the source-facing member name.

The byte at `this + 0x130` is descriptor offset `+0x28`, corresponding to the `ObjectStatusBlob` display/default byte (`m_displayStatusByte` / `defaultByte`). The constructor writes `0x50` there before copying the incoming descriptor, then the `0x44`-byte copy overwrites the same byte for ordinary non-aliasing arguments. Treat this as a source-order default initialization before assignment, not as an independent pane render-state field.

Object-image paint dispatch uses the descriptor kind at offset `+0`:

| Kind | Source-draft enum alias | Render library |
| --- | --- | --- |
| `0` | `ObjectStatusBlob::HumanObject` / `HumanAppearance` | `g_pNewHumanImageLib` (`NewHumanImageLib::CalculateBounds`, `NewHumanImageLib::Draw`) |
| `1` | `ObjectStatusBlob::MonsterObject` / `MonsterAppearance` | `g_pMonsterImageLib` (`MonsterImageLib::ComputeRenderBounds`, `MonsterImageLib::RenderMonsterImage`) |
| `2` | `ObjectStatusBlob::ItemObject` / `ItemAppearance` | `g_pItemObjImageLib` (`GetItemGlyphBounds`, `ItemObjImageLib::DrawItemImage`) |

For the item/EPF branch, descriptor offset `+4` is the item/appearance id and descriptor offset `+6` is the variant/palette byte. HeadSelect uses the same offsets as `headIndex` and `headDrawOffset` for the human branch; those names should stay caller-specific aliases, not the generic descriptor field names.
```

### 4. Evidence Addendum

Recommended addendum:

```markdown
### B008 Source-Quality Recheck (2026-06-19)

B008 could not reach the local IDA MCP endpoint, so this pass rechecked the range directly against raw `NexusTK.exe` bytes with Capstone and cross-checked existing live IDA-backed docs. The constructor body is `0x00520540-0x005205b5` half-open and ends with `ret 8`; padding begins at `0x005205b5`. The paint virtual remains `0x005205c0-0x00520816`, with padding at `0x00520816-0x00520820`.

The constructor calls `ControlPane::ControlPane(8, bounds)`, installs the three `ObjectImageControlPane` vtable views, writes descriptor byte `+0x28` / object offset `+0x130` to `0x50`, and copies exactly `0x44` bytes from the incoming descriptor into `this+0x108..0x14b`. A PE-level direct-call scan found 28 calls to the constructor. Visible call sites consistently push the bounds pointer first and the descriptor pointer second, so the source-facing signature is `ObjectImageControlPane(const ObjectStatusBlob *objectStatus, const RectBounds *bounds)`.

The paint virtual uses no stack arguments and branches on `m_objectStatus.m_statusKind`. It prepares the draw state through `EPFTileContext::InitTileContext`, `GrafPort::SetDrawColor(0)`, and `SurfaceRenderCallbackTable` slot `0x0069b3fc(this, &m_bounds)`, then measures and centers the requested image before dispatching to the human, monster, or item image library. The item branch directly reads descriptor word `+4` and byte `+6`; human and monster branches pass the full descriptor to their render libraries.

The non-contiguous thunks at `0x00520afd` and `0x00520b08` only adjust secondary/tertiary vtable `this` pointers and jump to the scalar deleting destructor. The scalar deleting destructor calls shared pane-base teardown `0x00544580`, then optional delete helpers, with guarded size `0x14c`. These are compiler-generated support bytes and should remain outside the target C++ block.
```

### 5. Reconstruction C++ Insertion

Recommended first-draft target C++:

```cpp
ObjectImageControlPane::ObjectImageControlPane(const ObjectStatusBlob *objectStatus,
                                               const RectBounds *bounds)
    : ControlPane(8, bounds)
{
    m_objectStatus.m_displayStatusByte = 0x50;
    m_objectStatus = *objectStatus;
}

void ObjectImageControlPane::OnPaint()
{
    EPFTileContext tileContext;
    RectBounds imageBounds;
    RectBounds destBounds;

    tileContext.InitTileContext();
    SetDrawColor(0);
    SurfaceRenderCallbackTable::PreparePaneRegion(this, &m_bounds);

    if (m_objectStatus.m_statusKind == ObjectStatusBlob::HumanObject) {
        g_pNewHumanImageLib->CalculateBounds(&m_objectStatus,
                                             NewHumanImageLib::PreviewRender,
                                             &imageBounds);

        const int x = ((m_bounds.left + m_bounds.right) / 2) -
            ((imageBounds.right - imageBounds.left) / 2);
        const int y = ((m_bounds.top + m_bounds.bottom) / 2) -
            ((imageBounds.bottom - imageBounds.top) / 2);

        destBounds.left = x;
        destBounds.top = y;
        destBounds.right = x + (imageBounds.right - imageBounds.left);
        destBounds.bottom = y + (imageBounds.bottom - imageBounds.top);

        g_pNewHumanImageLib->Draw(this,
                                  &destBounds,
                                  &m_objectStatus,
                                  NewHumanImageLib::PreviewRender);
        return;
    }

    if (m_objectStatus.m_statusKind == ObjectStatusBlob::MonsterObject) {
        g_pMonsterImageLib->ComputeRenderBounds(&m_objectStatus,
                                                MonsterImageLib::PreviewRender,
                                                &imageBounds);

        const int x = ((m_bounds.left + m_bounds.right) / 2) -
            ((imageBounds.right - imageBounds.left) / 2);
        const int y = ((m_bounds.top + m_bounds.bottom) / 2) -
            ((imageBounds.bottom - imageBounds.top) / 2);

        destBounds.left = x;
        destBounds.top = y;
        destBounds.right = x + (imageBounds.right - imageBounds.left);
        destBounds.bottom = y + (imageBounds.bottom - imageBounds.top);

        g_pMonsterImageLib->RenderMonsterImage(this,
                                               &destBounds,
                                               &m_objectStatus,
                                               MonsterImageLib::PreviewRender);
        return;
    }

    if (m_objectStatus.m_statusKind == ObjectStatusBlob::ItemObject) {
        g_pItemObjImageLib->GetItemGlyphBounds(m_objectStatus.m_appearanceId,
                                               &imageBounds);

        const int x = ((m_bounds.left + m_bounds.right) / 2) -
            ((imageBounds.right - imageBounds.left) / 2);
        const int y = ((m_bounds.top + m_bounds.bottom) / 2) -
            ((imageBounds.bottom - imageBounds.top) / 2);

        destBounds.left = x;
        destBounds.top = y;
        destBounds.right = x + (imageBounds.right - imageBounds.left);
        destBounds.bottom = y + (imageBounds.bottom - imageBounds.top);

        g_pItemObjImageLib->DrawItemImage(this,
                                          &destBounds,
                                          m_objectStatus.m_appearanceId,
                                          m_objectStatus.m_variantOrPalette,
                                          0,
                                          0);
    }

    tileContext.ReleaseBuffers();
}
```

Notes on this draft:

- `SurfaceRenderCallbackTable::PreparePaneRegion` is a recommended descriptive alias for the `0x0069b3fc` callback slot. If support docs standardize a different final name, update the draft to match.
- `HumanObject`, `MonsterObject`, `ItemObject`, `m_appearanceId`, `m_variantOrPalette`, and `m_displayStatusByte` are high-probability/descriptive names. The exact original spellings are not symbol-proven.
- The high-level `CalculateBounds`/`Draw` signatures intentionally hide raw zero/flag parameters. If the accepted render-library headers do not provide preview overloads yet, support docs should add source-facing wrapper declarations or expand the calls with named constants in the implementation callback.
- Do not include vtable stores, scalar deleting destructor code, adjustor thunk code, or raw `dword_*` names in formal C++.

### 6. Change Log Entry

Recommended target change-log entry:

```markdown
- 2026-06-19 B008 source-quality pass:
  - Before: `COMPLETION:85`, `CONFIDENCE:86`, owner/emitter [UID:0000M3], final C++ blank due descriptor/source-name blockers.
  - Recommended: `COMPLETION:90`, `CONFIDENCE:91`, preferred owner/emitter [UID:00009O] with source route through [UID:0000M3], and first-draft constructor/paint C++ populated.
  - Summary/evidence: raw PE/Capstone recheck and existing live IDA-backed docs resolve the constructor signature as `ObjectImageControlPane(const ObjectStatusBlob *objectStatus, const RectBounds *bounds)`, correct the constructor half-open endpoint to `0x005205b5`, identify the copied member as a 68-byte `ObjectStatusBlob` at `+0x108..+0x14b`, classify byte `+0x130` as descriptor offset `+0x28` default/display byte rather than an independent pane field, confirm 28 direct constructor calls, confirm `OnPaint()` dispatch through `g_pNewHumanImageLib` / `g_pMonsterImageLib` / `g_pItemObjImageLib`, confirm centered `RectBounds` arithmetic, and keep vtables/thunks/scalar deleting destructor as compiler/generated support outside target C++.
```

## Recommended Support Doc Changes

Do not apply until a supervisor sends an implementation callback.

### [UID:00009O] `by-class/ObjectImageControlPane.md`

Recommended changes:

- Score: `85/86 -> 88/90`.
- Update constructor row to `0x00520540-0x005205b5` and signature `ObjectImageControlPane(const ObjectStatusBlob *objectStatus, const RectBounds *bounds)`.
- Update paint row to `void OnPaint()`.
- Replace "final C++ withheld because descriptor field names/source declaration unresolved" with "first-draft method C++ ready; exact render-library flag names and original ObjectStatusBlob member spellings remain below final-audit."
- Add field note:

```markdown
| `+0x108..+0x14b` | `ObjectStatusBlob m_objectStatus` / `m_imageStatus` | 68-byte copied object appearance/status descriptor. Offset `+0x130` is descriptor byte `+0x28` (`m_displayStatusByte` / `defaultByte`), not a separate pane field. |
```

### [UID:0000M3] `by-file/ObjectImageControlPane.md`

Recommended changes:

- Score: `86/86 -> 88/88`.
- Keep proposed path `NexusTK/ui/controls/`.
- Replace constructor evidence endpoint `0x00520540-0x005205b4` with `0x00520540-0x005205b5`.
- State that the plain control and button subclass should share `ObjectStatusBlob` descriptor naming.
- State that current target first-draft C++ is ready and that the emitted source should include constructor/paint bodies but not vtable/thunk/scalar-delete/rdata bytes.
- Keep `ObjectImageButtonPane` in the same source family; do not move to `SpecializedButtonPanes`.

### [UID:0001BV] `by-memory/0x00520820-0x00520a90.ObjectImageButtonPaneCore.md`

Recommended support-only changes:

- Keep score unless implementation expands the button paint/key source-quality too.
- Update constructor signature direction to:

```cpp
ObjectImageButtonPane::ObjectImageButtonPane(const ObjectStatusBlob *objectStatus,
                                             const RectBounds *bounds);
```

- Add that the button inherits the copied `ObjectStatusBlob m_objectStatus` at base offset `+0x108..+0x14b`, and its own byte at `+0x14c` follows the base size `0x14c`.

### [UID:00009N] `by-class/ObjectImageButtonPane.md`

Recommended support-only changes:

- Replace "image descriptor structure unresolved" with the same `ObjectStatusBlob` direction.
- Keep final button C++ blank unless a separate button source-quality callback resolves the key/paint/highlight method drafts.

### [UID:00009S] / [UID:000179] / [UID:0000M6] `ObjectStatusBlob` docs

Recommended support text:

```markdown
Object-image controls use the `+0` status kind as an image-library dispatch selector: `0` renders full human/avatar appearance through `NewHumanImageLib`, `1` renders monster appearance through `MonsterImageLib`, and `2` renders item/EPF appearance through `ItemObjImageLib`. MapPane can still group kinds `0` and `1` as living-object map panes, but object-image UI should use the more specific `HumanObject`/`MonsterObject`/`ItemObject` or `HumanAppearance`/`MonsterAppearance`/`ItemAppearance` aliases when discussing render dispatch.
```

This reconciles the MapPane draft's `FullLivingObject`/`CompactLivingObject` wording with target-local render evidence. No score change required unless the support pages are otherwise refreshed.

### Image-library support docs

Recommended support-only aliases:

- [UID:000092]/[UID:0000LR] `NewHumanImageLib`: `0x004e09e0` as `CalculateBounds` / `CalculateHumanBounds`, `0x004e06a0` as `Draw` / `RenderHuman`, used by object-image preview path with preview/render mode constant `2`.
- [UID:00008N]/[UID:0000LJ] `MonsterImageLib`: `0x004db5c0` as `ComputeRenderBounds`, `0x004db3b0` as `RenderMonsterImage`, used by object-image preview path with preview/render mode constant `3`.
- [UID:00006W]/[UID:0000KH] `ItemObjImageLib`: `0x004df460` as `GetItemGlyphBounds`, `0x004dee50` as `DrawItemImage`, using descriptor `m_appearanceId` and `m_variantOrPalette`.

### Render support docs

Recommended support-only aliases:

- [UID:0000XY]/[UID:0000J4] `EPFTileContext`: keep `0x00457a60` as `InitTileContext` and `0x00458500` as `ReleaseBuffers`.
- [UID:000162] `GrafPortDrawStateAccessors`: note this target uses `0x004b9660` as `SetDrawColor(0)`.
- [UID:0001PI]/[UID:0000TN] `SurfaceRenderCallbackTable`: this target calls slot `0x0069b3fc(this, &m_bounds)` as a pane-region preparation/refresh callback. Prefer a descriptive slot name such as `PreparePaneRegion` over `g_pfnLockSurface`.

## Score / Metadata Recommendation

Recommended target score change: `85/86 -> 90/91`.

Why completion increases:

- Constructor and paint exact ranges are resolved, including constructor off-by-one endpoint.
- Descriptor type, member offset, and `+0x130` semantics are resolved enough for source.
- Constructor signature and argument order are confirmed from raw constructor and 28 call sites.
- Paint virtual name/signature and library dispatch are resolved.
- Compiler-generated thunks/scalar deleting destructor/rdata boundaries are explicitly excluded from handwritten target C++.
- First-draft C++ is supplied.

Why confidence increases:

- Existing live IDA-backed docs and fresh raw PE/Capstone agree on boundaries, behavior, global dependencies, and caller fanout.
- Sibling `ObjectImageButtonPane` and `HeadSelectDialog` docs independently confirm descriptor type and argument order.
- Object size evidence from scalar deleting destructors confirms descriptor extent and subclass field start.

Why not `95+`:

- Local live IDA MCP was unavailable for this report.
- Original source spellings for `ObjectStatusBlob` enum/member names are still descriptive, not symbol-proven.
- `SurfaceRenderCallbackTable` slot and image-library preview flag/parameter names need broader support/header normalization.
- Button subclass C++ remains a separate source-quality task.

## First-Draft C++ Readiness

Status: ready to populate in the target after supervisor implementation callback.

Gate check:

- `RECONSTRUCTABLE:TRUE`: yes.
- Nonblank emitter route: yes; current route [UID:0000M3], recommended precise route [UID:00009O] -> [UID:0000M3].
- Combined score after recommendation: `(90 + 91) / 2 > 85`: yes.
- Source shape resolved: yes for target constructor and paint.

Do not populate C++ for:

- `0x00520afd` / `0x00520b08` adjustor thunks.
- `0x00520ca0` scalar deleting destructor wrapper.
- `0x0061f6c0` / `0x0061f728` / `0x0061f758` rdata vtable bytes.
- `ObjectImageButtonPane` methods in [UID:0001BV], unless a separate accepted implementation callback covers that sibling.

## Validator Needs

No validator run was required for this report-only pass.

If the supervisor sends an implementation callback for the target, recommended validation after target edit:

> Executable block R001 was removed from this report and preserved verbatim in [0001BU-ObjectImageControlPane-source-quality-removed.md](0001BU-ObjectImageControlPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support docs are updated in the same callback, validate each edited support page, for example:

> Executable block R002 was removed from this report and preserved verbatim in [0001BU-ObjectImageControlPane-source-quality-removed.md](0001BU-ObjectImageControlPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After C++ insertion, run an autogen dry-run or apply per supervisor preference:

> Executable block R003 was removed from this report and preserved verbatim in [0001BU-ObjectImageControlPane-source-quality-removed.md](0001BU-ObjectImageControlPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not edit `by-memory/-coverage-report.md` as B008 while the supervisor ban is active.

## Exact Pending Coverage Text

Replace the existing [UID:0001BU] row in `source-3/project-documentation/by-memory/-coverage-report.md` with:

```markdown
    - [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) 0x00520540-0x00520816 | class-method-cluster | ObjectImageControlPane : reconstructable : 90% : very-strong : B008 2026-06-19 source-quality reanalysis resolves the constructor signature as `ObjectImageControlPane(const ObjectStatusBlob *objectStatus, const RectBounds *bounds)`, corrects the constructor half-open subrange to `0x00520540-0x005205b5`, identifies the copied descriptor as shared 68-byte `ObjectStatusBlob m_objectStatus` at `+0x108..+0x14b`, classifies `+0x130` as descriptor byte `+0x28` (`m_displayStatusByte` / `defaultByte`) rather than an independent pane field, confirms 28 direct constructor calls with descriptor-first/bounds-second source order, confirms `void OnPaint()` dispatch through `g_pNewHumanImageLib`, `g_pMonsterImageLib`, and `g_pItemObjImageLib`, records centered `RectBounds` paint math and item branch reads of descriptor `+4/+6`, keeps object-image button as same-family subclass support, excludes vtables/thunks/scalar deleting destructor as generated/source-declared support, recommends direct class owner/emitter [UID:00009O] routed through [UID:0000M3], and supplies first-draft constructor/paint C++.
```

## Follow-Up Actions

Supervisor actions:

- Review this report before implementation.
- If accepted, send B008 an implementation checklist covering target metadata, target evidence text, C++ insertion, selected support doc updates, validation commands, and the supervisor-owned coverage row above.
- Apply/update `by-memory/-coverage-report.md` separately while the shared-file edit ban remains active.

B008 implementation callback actions, if requested:

- Lease any by-* target/support docs before editing.
- Apply accepted target and support changes.
- Run validator commands.
- Report changed files and validation output.

Future research outside this exact target:

- Separate source-quality pass for [UID:0001BV] `ObjectImageButtonPaneCore` should use the descriptor/signature findings here, then resolve its key handler, paint overlay/highlight field names, and first-draft C++.
- Broader `ObjectStatusBlob` declaration pass should choose final enum names that satisfy both MapPane (`0/1` living branches) and object-image render dispatch (`0` human, `1` monster, `2` item/EPF).
- Render-library header pass should normalize exact source-facing overloads or named constants for the preview render calls into `NewHumanImageLib` and `MonsterImageLib`.

## Changed Files

Created report only:

```text
source-3/project-documentation/tools/leaser/Agents/Agent-B008/research/0001BU-ObjectImageControlPane-source-quality.md
```

No target by-memory docs changed. No support by-* docs changed. No generated/project-level files changed. No `by-memory/-coverage-report.md` edit performed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0001BU-ObjectImageControlPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"0001BU"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001BU-ObjectImageControlPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0001BU-ObjectImageControlPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001BU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
