** TARGET-REPORT-UID:000163 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID000163 DrawContext Brush Handle Helpers Empty-Emitter Source-Quality Research

## Finalized Report / Current Recommendation

- Implemented result reclassifies the historical `GetBrushHandle` / `SetBrushHandle` pair as source-authored `GrafPort` palette accessors over the non-owning `DLPalette *` field at `this+0x84`.
- The exact half-open target range `0x004b96a0-0x004b96c0`, direct owner/emitter [UID:00005V] `GrafPort`, source route [UID:0000JR] `NexusTK/render/GrafPort.cpp`, `RECONSTRUCTABLE:TRUE`, blank emitter position, and `Nested:0` are preserved.
- Only the target moved from `86/90` to `90/92`; it now contains the exact managed definitions `DLPalette *GrafPort::GetPalette() const` and `void GrafPort::SetPalette(DLPalette *palette)`.
- `0x004b96a7-0x004b96b0` remains documented as nine bytes of compiler alignment, not source; the correctly bounded pair was not split and padding was not emitted.
- Historical brush-handle spellings remain aliases/provenance, while source-facing C++ and the existing `GrafPort::DrawGlyph` body now consistently use `m_palette`.
- Confidence is high for boundaries, bodies, ABI, `DLPalette *` type, borrowed lifetime, class/file ownership, and source eligibility; exact original identifiers and getter `const` qualification remain inferred and cap confidence below the high 90s.

## Supporting Research

- B004 searched current agent goals and research artifacts before drafting. No duplicate current UID000163 assignment and no retained B004 UID000163 report were found; historical material was used only as an evidence lead.
- MCP evidence was collected on 2026-07-12 from database `supervisor_20260712`. `idb_list` identified the configured NexusTK IDB worker, and `server_health` returned `ok` with auto-analysis, Hex-Rays, and string-cache readiness when the evidence pass was performed.
- The streamable MCP endpoint was initialized through JSON-RPC because named IDA tools were not present in the exposed child tool list. Successful `tools/list`, `idb_list`, `server_health`, and target `tools/call` results prove that this was not an MCP outage. No process-management action was taken.
- Pre-callback project documentation already routed the target through `GrafPort`, but preserved an older A003 interpretation of `this+0x84` as an opaque brush/palette handle and retained `m_brushHandle` in UID00016I formal C++.
- Fresh caller data narrows that slot to a borrowed `DLPalette *`: callers obtain actual palette objects from `PaletteLib`, mutate them through `DLPalette::SetColor` / `SetPackedColor`, install them into the GrafPort, and then restore or clear the previous pointer.
- Read-only generated snapshot command `000000008916`, refreshed `2026-07-12T22:19:11-04:00`, shows one UID000163 Empty Emitter Marker at `86/90` in `auto-generated/NexusTK/render/GrafPort.cpp` under the correct `GrafPort` route. This is an evidence-time snapshot, not a permanent lifecycle/count assertion.
- Report-only boundary: B004 edited no by-* document, acquired no lease, ran no validator/generated refresh, and ran no report execution, lifecycle, move, or archive command while producing this Gate 1 artifact.
- Gate 1 passed exact SHA `7DEF389ADB05B70F194117D408EC6BE39643272663F7B5BCC4B0CD8B646DC028`; the supervisor callback accepted C01-C30 and the exact bounded support list.
- Callback implementation changed only the target and eleven accepted support docs under immediate one-file leases, ran scoped validation after each edit, released every B004 lease, and completed final waited generated refresh `000000008958`. B004 performed no report execution, lifecycle, move, archive, MCP write, or process-management action.

## Target

- Target UID: `000163`.
- Target path: `by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md`.
- B004 artifact path at creation: `tools/leaser/Agents/Agent-B004/research/000163-DrawContextBrushHandleHelpers-empty-emitter-source-quality.md`; later validation/execution/path state is supervisor/validator-owned and external to the artifact.
- Assignment classification: reconstructable empty emitter requiring exact body, ABI, padding, field type/lifetime, complete caller inventory, names, owner/emitter route, source placement, blocker resolution, and formal first-draft C++.
- Pre-callback documented snapshot: `86/90`, `CANONICAL_OWNER:00005V`, `EMITTER_UIDS:00005V`, `RECONSTRUCTABLE:TRUE`, blank emitter position, `Nested:0`, and blank formal C++.
- Implemented callback state: `90/92` with all routing/range/nesting metadata preserved and the exact managed two-method block in this report and the target.

## Current Target State

- The current by-memory page identifies both leaf functions and the inter-function `0xcc` gap, types `+0x84` as borrowed `DLPalette *m_palette`, records all ten calls/four callers and field lifetime, and contains the exact formal C++.
- The page's old `95/95` code-entry gate and opaque brush-handle conclusion are retained only as historical superseded state.
- The direct owner/emitter route remains [UID:00005V] `GrafPort` -> [UID:0000JR] `GrafPort` -> `NexusTK/render/GrafPort.cpp`.
- Caller-biased `UserHairColorSelectListPane` generated ownership remains rejected; the current generated body is under `GrafPort`.
- The tracker row read after generated command `000000008916` showed `86/90`, reconstructable, `Nested:0`, and zero reports. That is a pre-callback derived snapshot and must not be frozen as permanent state.
- Final waited generated command `000000008958`, refreshed `2026-07-12T23:26:27-04:00`, contains exactly one UID000163 record, one getter definition, one setter definition, no target Empty Emitter Marker, one UID00016I record using `m_palette`, and no `m_brushHandle` token in `GrafPort.cpp`.
- A later concurrent validator-owned refresh advanced the read-only GrafPort.cpp header to command `000000008972`, refreshed `2026-07-12T23:27:46-04:00`; the same exact counts/body proof remained unchanged. B004 did not run that external refresh.
- No split, child creation, owner move, file move, new source file, fabricated ownership/lifetime behavior, or implementation item remains.

## Executive Recommendation

- Two ordinary `GrafPort` member definitions now emit in `NexusTK/render/GrafPort.cpp` over source-facing `DLPalette *m_palette` at `+0x84`.
- The emitted getter is `DLPalette *GrafPort::GetPalette() const`; the emitted setter is `void GrafPort::SetPalette(DLPalette *palette)`, correctly discarding incidental EAX assignment residue.
- Every direct use remains documented: constructor null initialization, DrawGlyph callback forwarding, custom-color save/install/restore, and appearance swatch install/clear.
- No palette ownership, reference counting, deletion, validation, copying, automatic restoration, duplicate body, or fabricated call was introduced.

## Supervisor Active Recheck

- Current goals/reports were searched before research and no duplicate current UID000163 workstream was found.
- Exact target, predecessor, successor, class, file, aggregate, DrawGlyph, palette, balloon, chat, hair-color, and face-color documentation were inspected.
- MCP session `supervisor_20260712` was healthy when all recorded binary evidence was collected. No indefinite current-availability assertion is made.
- Gate 1 report-only rules were observed: no by-* edit, validator, lease, generated edit/refresh, tracker/coverage edit, report execution, or lifecycle operation occurred.
- Gate 1 passed the exact report SHA named above. The accepted callback is complete, each changed page passed its scoped validator, and waited generated proof is recorded below.

## Inference Research Guidance Check

- Direct binary facts, current documentation facts, and source-shape inference are separated throughout this report.
- Existing assumptions treated as uncertain were `brush handle` type, `GetBrushHandle` / `SetBrushHandle`, `m_brushHandle`, setter return type, getter `const`, and possible feature-class ownership.
- The evidence ladder was applied from exact bytes/disassembly, through xrefs and caller data flow, to canonical `DLPalette` methods and adjacent GrafPort accessors, then to the narrowest source-facing names.
- No decompiler placeholder, generated caller owner, or historical recovered source label is promoted as original-symbol proof.
- The recommendation does not add an abstraction: it expresses the exact field read/write already present in the binary using the strongest proven project type.

## Heuristic / Inference Reanalysis And Validation

- **Boundary blocker:** live lookup identifies getter `0x004b96a0-0x004b96a7`, no function at `0x004b96a7`, setter `0x004b96b0-0x004b96c0`, and successor UID000164 at `0x004b96c0`. The existing pair range is exact; no split is needed.
- **Padding blocker:** bytes `0x004b96a7-0x004b96b0` are exactly nine `0xcc` bytes. They are alignment between two source methods and must not appear in formal C++.
- **Getter type blocker:** callers preserve the returned dword and later pass it back to the setter. Other callers install pointers returned by PaletteLib helpers and invoke `DLPalette` methods on those same objects. Resolve the getter as `DLPalette *`, not `int`, `void *`, palette index, GDI brush, or owned resource.
- **Setter return blocker:** the setter loads the stack argument into EAX solely to store it, then returns. Callers do not consume a semantic return, and adjacent GrafPort state setters are source-modeled `void`. Resolve as `void` with EAX assignment residue.
- **Lifetime blocker:** constructor initializes `+0x84` to null; destructor does not release it; callers either save/restore or install/clear. Resolve as a borrowed, non-owning pointer.
- **Field-use blocker:** a direct `+84h` scan over the GrafPort range finds exactly constructor initialization, getter read, setter write, and DrawGlyph callback consumption. This excludes a hidden owner-managed field protocol.
- **Name blocker:** `brush handle` is too opaque and suggests a GDI-style handle contradicted by `DLPalette` method calls. `GetPalette` / `SetPalette` and `m_palette` are the highest-probability human names; `GetBrushPalette` / `SetBrushPalette` remain plausible but weaker descriptive alternatives.
- **Const blocker:** the getter reads only receiver state and mutates nothing. Use `const` as the best source declaration, explicitly retaining it as an inference rather than ABI-proven text.
- **Ownership blocker:** the helper receiver is the same GrafPort object whose constructor and DrawGlyph use `+0x84`; caller classes only consume the accessor. Retain direct GrafPort ownership.
- **Emitter blocker:** the accepted class/file chain already emits adjacent GrafPort methods into `render/GrafPort.cpp`; no separate PaletteLib, Balloon, Chatting, appearance, Surface, or utility file is supported.
- **Empty-emitter blocker:** blank C++ came from unresolved field/name language and an obsolete score gate, not missing behavior. Exact bodies and complete data flow now support formal source.
- **Generated-owner blocker:** hair, face, balloon, and chat paths are consumers. Broad fan-in is positive evidence for shared GrafPort ownership and negative evidence against any one feature class.
- **Score blocker:** exact bodies, bounds, all direct callers, type, lifetime, ownership, and source route are resolved. Only original spellings and textual `const` remain uncertain, supporting `90/92` rather than `95+`.

## Evidence Standards Used

- IDA MCP: refreshed `tools/list`, `idb_list`, `server_health`, function lookup, function analysis, decompilation, disassembly/bytes, xrefs, range signature, text search, integer conversion, and type-query checks.
- Binary evidence: exact function sizes, instruction sequences, `retn` forms, field displacement `0x84`, call sites, caller-local data flow, constructor initialization, destructor behavior, and DrawGlyph callback argument.
- Documentation evidence: current target, GrafPort class/file/aggregate, adjacent accessors and clip helper, DrawGlyph, PaletteLib/DLPalette, balloon/chat draw docs, appearance aggregate, hair/face class docs, current generated marker, and tracker snapshot.
- Inference evidence: original member/method spellings and getter `const`; each is labeled inferred and scored conservatively.
- Negative evidence: no alternate receiver class, no ownership release, no opaque-handle-only use, no return consumption, no child/split need, and no source-declared padding.

## Evidence Checked

- MCP session checks: `idb_list` and `server_health(database=supervisor_20260712)` succeeded before target analysis.
- Boundary checks: `lookup_funcs` around `0x004b9690`, `0x004b96a0`, `0x004b96a7`, `0x004b96b0`, and `0x004b96c0`; exact target bytes; unique range signature.
- Body checks: getter/setter `analyze_function`, decompilation, disassembly, calling convention, callee count, and basic-block count.
- Xref checks: every xref to getter and setter, then decompilation/disassembly of all four containing callers.
- Type checks: `PaletteLib::GetSlotPalette`, the embedded-palette helper at `0x00543d60`, `DLPalette::SetColor`, `DLPalette::SetPackedColor`, and current DLPalette/PaletteLib docs.
- Lifetime checks: GrafPort constructor `0x004b8bf0`, destructor `0x004b8d20`, direct `+84h` scan, and DrawGlyph use at `0x004bb7aa`.
- Documentation checks: UID000162, UID000163, UID000164, UID000160, UID00016I, GrafPort class/file, BalloonObjectPane class/aggregate, ColorStringChattingMessage class/draw child, UserCreateAppearance aggregate, and hair/face color-list classes.
- During the initial report-only phase, generated/tracker checks were read-only and no IDA write, by-* edit, lease, validator, generated refresh, or lifecycle action was performed. During the accepted callback, only the named by-* pages were edited; generated/tracker/coverage changes came solely from the validator commands recorded below.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Applied action | Callback verification |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Exact target range remains `0x004b96a0-0x004b96c0` (32 bytes). | High | lookup/bytes/signature/successor | Target metadata/range | preserved and expanded proof | Verified target `000000008933`. |
| C02 | Getter is `0x004b96a0-0x004b96a7`, seven bytes. | High | function size/disassembly | Target function map | incorporated | Verified target `8933`. |
| C03 | Getter body is `mov eax,[ecx+84h]; retn`. | High | live disassembly/decompile | Target behavior/C++ | incorporated | Verified target `8933`; emitted body `8958`. |
| C04 | `0x004b96a7-0x004b96b0` is nine `0xcc` alignment bytes. | High | exact bytes | Target range notes | incorporated; no source emission | Verified target `8933`; generated body omits padding `8958`. |
| C05 | Setter is `0x004b96b0-0x004b96c0`, 16 bytes. | High | function size/disassembly | Target function map | incorporated | Verified target `8933`. |
| C06 | Setter stores its sole stack argument at `this+0x84` and returns with `retn 4`. | High | live disassembly/decompile | Target ABI/behavior/C++ | incorporated | Verified target `8933`. |
| C07 | Source setter return is `void`; EAX is incidental assignment residue. | High | call-site use and adjacent setters | Target signature/C++ | incorporated | Verified target `8933`; exact void definition `8958`. |
| C08 | Getter has exactly two direct calls, at `0x00467fc2` and `0x004837a7`. | High | xrefs | Target caller inventory | incorporated | Verified target `8933`, Balloon `8943`/`8944`, chat `8945`/`8947`. |
| C09 | Setter has exactly eight direct calls at `0x0046801f`, `0x00468229`, `0x004837b2`, `0x004837fd`, `0x00502037`, `0x0050206f`, `0x005022f7`, and `0x0050232f`. | High | xrefs | Target caller inventory | incorporated | Verified target `8933` and caller docs `8939`-`8947`. |
| C10 | Balloon PaintBubble saves, installs, and restores the GrafPort palette pointer. | High | caller decompile/disassembly | Target; Balloon support | incorporated | Verified target `8933`, class `8943`, aggregate `8944`. |
| C11 | ColorStringChattingMessage draw saves, installs, and restores the palette during custom RGB overrides. | High | caller decompile/disassembly | Target; chat support | incorporated | Verified target `8933`, class `8945`, draw child `8947`. |
| C12 | Hair-color DrawItem installs PaletteLib slot-14 palette and clears it after the swatch draw. | High | caller data flow | Target; hair support | incorporated | Verified target `8933`, appearance `8939`, hair class `8940`. |
| C13 | Face-color DrawItem installs PaletteLib slot-13 palette and clears it after the swatch draw. | High | caller data flow | Target; face support | incorporated | Verified target `8933`, appearance `8939`, face class `8941`. |
| C14 | Values stored at `+0x84` are `DLPalette *`. | High | PaletteLib returns and DLPalette method use | Target type/field/C++ | incorporated | Verified target `8933`, GrafPort docs `8934`/`8935`/`8936`/`8938`/`8957`, caller docs `8939`-`8947`. |
| C15 | GrafPort constructor initializes `+0x84` to null. | High | constructor decompile/disassembly | Target lifetime; GrafPort support | incorporated | Verified target `8933`, class/aggregate `8934`/`8936`. |
| C16 | GrafPort destructor does not release/delete `+0x84`. | High | destructor analysis | Target lifetime | incorporated | Verified target `8933`, class/aggregate `8934`/`8936`. |
| C17 | DrawGlyph forwards `+0x84` as the palette argument to the sprite-blit callback. | High | direct field use/callback call | Target; UID00016I | incorporated | Verified UID00016I `8938`/`8957`; generated `m_palette` call `8958`. |
| C18 | Exactly four direct GrafPort-range `+84h` references exist: constructor, getter, setter, DrawGlyph. | High | range text/disassembly search | Target field evidence | incorporated | Verified target `8933` and GrafPort support `8934`/`8936`/`8938`/`8957`. |
| C19 | Field lifetime is borrowed/non-owning; callers save/restore or install/clear. | High | C10-C18 | Target lifetime | incorporated | Verified target `8933` plus bounded callers `8939`-`8947`. |
| C20 | Best source field name is inferred `m_palette`; historical `m_brushHandle` is retained as an alias only. | Medium-high | type/use/naming evidence | Target, GrafPort, UID00016I | source-facing use replaced | Verified `8933`-`8938` and final DrawGlyph `8957`; generated `m_brushHandle` count zero `8958`. |
| C21 | Best source method names are inferred `GetPalette` and `SetPalette`. | Medium-high | exact role/project naming | Target/GrafPort | source-facing use replaced | Verified target/class/file `8933`-`8935`; one definition each `8958`. |
| C22 | Getter should be `const`; this is source-shape inference, not ABI proof. | Medium-high | read-only body/style | Target C++/caveat | incorporated | Verified target `8933`; exact const definition `8958`. |
| C23 | Direct owner/emitter remain UID00005V GrafPort. | High | receiver field and class route | Target metadata | preserved | Verified target `8933`, class/file `8934`/`8935`, generated route `8958`. |
| C24 | Source placement remains UID0000JR `NexusTK/render/GrafPort.cpp`. | High | class/file route and adjacency | Target/GrafPort file | preserved | Verified file `8935`; generated path/header `8958`. |
| C25 | Feature consumers, PaletteLib, DLPalette, Surface, and generic DrawContext do not own the methods. | High | receiver/caller/dependency analysis | Target negative evidence | rejections recorded | Verified target `8933` and caller supports `8939`-`8947`. |
| C26 | No split/new child/new file is warranted. | High | exact two-body/padding range | Target range/source placement | preserved | Verified target `8933`; one target record `8958`. |
| C27 | Target score moved `86/90 -> 90/92`; other doc scores remain unchanged. | High | blocker resolution/residual uncertainty | Target metadata/support docs | applied target only | Target `8933`; support header audit after `8958` confirms unchanged scores. |
| C28 | Preserve `RECONSTRUCTABLE:TRUE`, blank emitter position, range, owner/emitter, and `Nested:0`. | High | current metadata and relative nesting | Target managed metadata | preserved | Verified target `8933`. |
| C29 | Exact managed first-draft C++ is the two-method block below. | High | C03, C06-C07, C14, C20-C22 | Target managed C++ | inserted exactly | Verified target `8933`; exact generated definitions `8958`. |
| C30 | The pre-callback empty marker was caused by blank formal C++, not no-code/no-owner evidence. | High | generated route and target metadata | Target status/change record | blocker historicalized | Verified target `8933`; target Empty Emitter Marker count zero `8958`. |

## Positive Evidence Summary

- The two function bodies are complete, unique, leaf-level, and exactly bounded by predecessor/successor functions and alignment.
- All ten direct helper calls are explained by four rendering functions; no xref remains semantically unclassified.
- Every stored non-null value comes from a PaletteLib path yielding a `DLPalette` object, and custom-color callers invoke `DLPalette` mutators on the same object before installation.
- Constructor initialization, no destructor release, and caller save/restore or set/clear patterns converge on a borrowed pointer.
- DrawGlyph directly consumes the same field as the palette parameter of the sprite-blit callback.
- The adjacent GrafPort accessor cluster, class page, file page, and generated route all support GrafPort ownership and `render/GrafPort.cpp` placement.

## IDA MCP Facts

- Database: `supervisor_20260712`; health was `ok` when evidence was collected.
- NexusTK IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; image base `0x00400000`; auto-analysis and Hex-Rays available.
- Unique target signature: `8B 81 84 00 00 00 C3 CC CC CC CC CC CC CC CC CC 55 8B EC 8B 45 08 89 81 84 00 00 00 5D C2 04 00`.
- Getter: one basic block, zero callees, load from `[ecx+0x84]`, plain `retn`.
- Setter: one basic block, zero callees, one stack argument, store to `[ecx+0x84]`, `retn 4`.
- Integer conversions: `0x84=132`, `0x20=32`, `0x7=7`, `0x10=16`, and PaletteLib embedded offset `0x464=1124`.
- IDA has no GrafPort or DLPalette UDT sufficient to prove original identifiers; names therefore remain evidence-based source inference.

## Function / Child Inventory

| Range | Bytes | Source disposition | Evidence |
| --- | ---: | --- | --- |
| `0x004b9690-0x004b96a0` | 16 | predecessor GrafPort setter outside target | modeled predecessor boundary |
| `0x004b96a0-0x004b96a7` | 7 | `GrafPort::GetPalette` | modeled leaf getter |
| `0x004b96a7-0x004b96b0` | 9 | compiler alignment, no source declaration | nine `0xcc` bytes |
| `0x004b96b0-0x004b96c0` | 16 | `GrafPort::SetPalette` | modeled leaf setter |
| `0x004b96c0-0x004b9768` | 168 | successor UID000164 outside target | modeled successor boundary |

- The existing target should remain one by-memory item because it intentionally groups a natural accessor pair and the alignment between them.
- No child page would improve source reconstruction or ownership precision.

## Direct Xref / Caller Inventory

| Helper/call site | Containing function | Exact role |
| --- | --- | --- |
| getter `0x00467fc2` | `BalloonObjectPane::PaintBubble` at `0x00467b30` | save current GrafPort palette before custom-color install |
| setter `0x0046801f` | `BalloonObjectPane::PaintBubble` | install PaletteLib embedded palette after `SetColor` updates |
| setter `0x00468229` | `BalloonObjectPane::PaintBubble` | restore saved GrafPort palette after packed-color restoration |
| getter `0x004837a7` | `ColorStringChattingMessage::Draw` at `0x004836a0` | save current palette before temporary custom RGB override |
| setter `0x004837b2` | `ColorStringChattingMessage::Draw` | install temporary PaletteLib embedded palette |
| setter `0x004837fd` | `ColorStringChattingMessage::Draw` | restore saved palette after text draw and color restoration |
| setter `0x00502037` | `UserHairColorSelectListPane::DrawItem` at `0x00501f30` | install slot-14 hair palette |
| setter `0x0050206f` | `UserHairColorSelectListPane::DrawItem` | clear palette to null after swatch drawing |
| setter `0x005022f7` | `UserFaceColorSelectListPane::DrawItem` at `0x005021f0` | install slot-13 face palette |
| setter `0x0050232f` | `UserFaceColorSelectListPane::DrawItem` | clear palette to null after swatch drawing |

- Getter xrefs: exactly two. Setter xrefs: exactly eight. Containing callers: exactly four.
- No caller consumes a setter return value or exhibits ownership transfer.

## Documentation Evidence And IDA Status

- UID000162 establishes adjacent source-authored GrafPort leaf accessors and `void` state-setter style.
- UID000160 and the GrafPort class/file pages already place UID000163 between draw-state accessors and `GetClipRect` under GrafPort.
- Before callback, UID00016I used `m_brushHandle` at `+0x84`; fresh type/caller evidence superseded that weak accepted spelling with `m_palette` while preserving the rest of DrawGlyph.
- DLPalette documentation establishes `SetColor`, `SetPackedColor`, object layout, and render-consumer use. PaletteLib documentation establishes long-lived palette objects returned to rendering code.
- ColorStringChattingMessage draw already records palette save/install/restore behavior but uses mixed brush/palette-handle wording that can now be narrowed.
- Before callback, UserCreateAppearance support retained a stale statement that UID000163 was emitted under `UserHairColorSelectListPane`; the implemented GrafPort owner metadata and generated route reject that historical statement.
- MCP was healthy at evidence time. No write-oriented IDA action was performed.

## Ranked Ownership Analysis

### 1. UID00005V GrafPort

- Evidence for: receiver `ecx` directly indexes the GrafPort field block; GrafPort constructor initializes the field; GrafPort DrawGlyph consumes it; adjacent methods are GrafPort accessors; current canonical owner/emitter already points here.
- Evidence against: exact original method/member symbols are absent.
- Decision: retain direct owner/emitter; missing symbols affect names, not class identity.

### 2. UID00003Z DLPalette or UID0000A1 PaletteLib

- Evidence for: the field type is `DLPalette *`, and installed objects come from PaletteLib.
- Evidence against: neither object is the receiver. They are value type/provider dependencies; the methods read/write GrafPort state.
- Decision: type/provider support only, not ownership.

### 3. BalloonObjectPane or ColorStringChattingMessage

- Evidence for: both save/install/restore the field during custom-color rendering.
- Evidence against: they call the helper on GrafPort objects and share it with unrelated appearance-list callers.
- Decision: consumer evidence only; reject feature-class ownership.

### 4. UserHairColorSelectListPane or UserFaceColorSelectListPane

- Evidence for: each installs a slot palette for swatch drawing.
- Evidence against: neither has getter calls; both pass a GrafPort receiver; caller-biased generated ownership is historical pollution.
- Decision: consumer evidence only; reject ownership and emitted placement.

### 5. Generic DrawContext, Surface, or standalone palette-state utility

- Evidence for: callers may describe the receiver generically and DrawGlyph forwards the field into a rendering callback.
- Evidence against: current class layout and constructor prove a GrafPort member; no separate class/file boundary or free-function ABI exists.
- Decision: reject new class, utility, owner, or file.

### Proposed new file/grouping, if applicable

- Not applicable. Keep the existing target under GrafPort and the existing `NexusTK/render/GrafPort.cpp` source route.

## Source Placement

- Direct class owner/emitter: [UID:00005V] `GrafPort`.
- File owner/source route: [UID:0000JR] `GrafPort`, path `NexusTK/render/GrafPort.cpp`.
- Placement rationale: both methods access only GrafPort receiver state and are physically/source-semantically adjacent to GrafPort state accessors and clip/render methods.
- PaletteLib/DLPalette are dependencies, and balloon/chat/appearance classes are callers. None warrants direct emission.
- No header/file split can be proven from the binary; only out-of-class definitions are recommended in the target block.

## Range / Split / Padding / Reclassification Analysis

- Retain exact half-open range `0x004b96a0-0x004b96c0`, total 32 bytes.
- Source method 1: `0x004b96a0-0x004b96a7`, seven bytes.
- Non-source alignment: `0x004b96a7-0x004b96b0`, nine `0xcc` bytes.
- Source method 2: `0x004b96b0-0x004b96c0`, 16 bytes.
- Predecessor ends exactly at target start; successor UID000164 starts exactly at target end.
- Retain `Nested:0`. The predecessor, target, and successor all have zero relative delta in address-sorted order; `Nested` is not a child count.
- Reclassify only semantic source readiness and naming: nonblank source-authored palette accessors, not an empty opaque-handle marker.

## Negative Evidence Summary

- No evidence supports a Windows `HBRUSH`, graphics API brush handle, integer palette ID, owned palette object, or reference-counted resource at `+0x84`.
- No destructor release or transfer-of-ownership path exists for the field.
- No caller semantically consumes the setter's EAX value.
- No feature caller exclusively owns the pair; fan-in crosses balloon, chat, hair, and face rendering.
- No class/file evidence supports PaletteLib, DLPalette, Surface, or generic DrawContext as the method owner.
- No separate source declaration corresponds to the nine alignment bytes.
- No original symbols prove `GetPalette`, `SetPalette`, `m_palette`, parameter name, or getter `const`; these remain explicit source inference.
- No split, new child, new owner, new file, or manual tracker/generated edit is justified.

## IDA Rename / Type / Comment Recommendations

- If a later supervisor-owned IDB annotation pass is performed, rename `sub_4B96A0` to `GrafPort::GetPalette` and `sub_4B96B0` to `GrafPort::SetPalette`.
- Apply source-facing prototypes `DLPalette *__thiscall GrafPort::GetPalette() const` and `void __thiscall GrafPort::SetPalette(DLPalette *palette)` if the IDA type system can represent the class.
- Annotate GrafPort `+0x84` as borrowed `DLPalette *m_palette`, initialized null and not released by GrafPort.
- Annotate `0x004b96a7-0x004b96b0` as alignment and the ten callers with save/install/restore or install/clear roles.
- No IDA rename, type application, function edit, or comment write was performed during this report-only assignment.

## First-Draft C++ Recommendation

- Eligible for first-draft C++: yes. Both methods, ABI, field type, lifetime, owner, and source route are resolved.
- Recommended exact managed target insertion:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DLPalette *GrafPort::GetPalette() const
{
    return m_palette;
}

void GrafPort::SetPalette(DLPalette *palette)
{
    m_palette = palette;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Body fidelity: getter performs one field read; setter performs one field write. No null check, ownership action, conversion, or callback is added.
- ABI fidelity: ordinary x86 member calls use ECX as receiver; setter has one four-byte stack argument and callee cleanup. Source `void` intentionally ignores incidental EAX residue.
- Type fidelity: `DLPalette *` is supported by provider and consumer data flow; a generic `void *` would discard proven type information.
- Name fidelity: `GetPalette`, `SetPalette`, `m_palette`, and `palette` are highest-probability inferred human names. Historical `GetBrushHandle`, `SetBrushHandle`, and `m_brushHandle` stay in prose as rejected/older aliases.
- `const` is recommended because the getter only reads receiver state; absence of original declarations remains a confidence cap.
- Third-party import directive: not applicable. This is NexusTK project source, not a third-party embed.
- No-code proof: not applicable. Blank C++ is rejected because both source methods are completely reconstructable.

## Final Recommendation

- C01-C30 are implemented at report-level detail in the bounded target/support set.
- Only UID000163 is `90/92`; owner/emitter UID00005V, reconstructable true, blank emitter position, exact range, and `Nested:0` remain unchanged.
- The exact managed two-method block is present, and source-facing opaque brush-handle wording is replaced by borrowed `DLPalette *m_palette` semantics while historical aliases remain preserved.
- GrafPort/DrawGlyph and bounded caller docs are synchronized without unrelated score, metadata, formal-method, or caller-behavior changes.
- Exact bytes, call sites, historical aliases, negative evidence, and residual naming/const uncertainty remain intact.
- No ownership cleanup, fabricated call, feature-class ownership, new child, new source file, or manual generated/tracker edit was added.

## Recommended Target Doc Changes

- Path: `by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md`.
- Applied `COMPLETION:86 -> 90` and `CONFIDENCE:90 -> 92`; all other managed metadata including owner/emitter UID00005V, reconstructable true, blank position, and `Nested:0` is preserved.
- Inserted the exact managed C++ block from this report.
- Replaced source-facing `GetBrushHandle` / `SetBrushHandle` and opaque brush/palette-handle claims with inferred `GetPalette` / `SetPalette`, borrowed `DLPalette *m_palette`, while retaining old spellings as historical aliases.
- Recorded exact range/body/padding bytes, setter-void reasoning, all ten call sites, four caller roles, constructor/DrawGlyph/destructor field-lifetime proof, owner/source placement, and rejected alternatives.
- Historicalized the obsolete `95/95` blank-C++ gate and caller-biased generated-owner snapshot.

## Recommended Support Doc Changes

- `by-class/GrafPort.md`: narrowed UID000163 and field `+0x84` to borrowed `DLPalette *m_palette`, used inferred `GetPalette` / `SetPalette`, and preserved class score, unrelated methods, and historical A003 evidence as superseded.
- `by-file/GrafPort.md`: updated only UID000163 source-ready route wording and the dated record; file score, route, and siblings are preserved.
- `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md`: changed only the UID000163 inventory/support facts to typed palette accessors with constructor/DrawGlyph/lifetime proof; aggregate score/non-emitting status and siblings are preserved.
- `by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md`: replaced only target-related `m_brushHandle` with `m_palette` in formal C++, field map, reconstruction note, and provenance summary; UID00016I score, metadata, all other body lines, and callback evidence are preserved.
- `by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md`: replaced stale current-emitter-under-hair wording with the GrafPort route and exact slot-14/slot-13 install/clear semantics; aggregate score/C++/metadata and unrelated children are preserved.
- `by-class/UserHairColorSelectListPane.md`: synchronized the helper row/support facts to slot-14 GrafPort palette install/clear and rejected class ownership; no score/metadata/C++ change.
- `by-class/UserFaceColorSelectListPane.md`: applied the parallel slot-13 palette install/clear and ownership rejection; no score/metadata/C++ change.
- `by-class/BalloonObjectPane.md`: expanded the helper note to exact save/install/restore of the PaletteLib embedded `DLPalette` during custom-color drawing; no score/metadata/C++ change.
- `by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md`: added the same exact PaintBubble palette accessor dependency without altering aggregate score, formal C++, or unrelated reconstruction.
- `by-class/ColorStringChattingMessage.md`: narrowed generic helper wording to exact save/install/restore of a temporary `DLPalette *`; no score/metadata/C++ change.
- `by-memory/0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md`: replaced mixed brush/palette-handle wording with typed GrafPort palette accessors while preserving draw score, metadata, body/tables, and all other evidence.
- No PaletteLib or DLPalette doc edit is required: their current type/method facts already support this target and contain no target-specific stale claim.

## Score And Metadata Recommendation

- Pre-callback target snapshot: `86/90`, direct owner/emitter UID00005V, reconstructable true, blank emitter position, `Nested:0`, blank C++.
- Implemented target: `90/92`, same owner/emitter/reconstructable/position/nesting, nonblank exact C++.
- Completion rises by four because exact method bodies, formal signatures, all callers, field type/lifetime, source names, and emitted source shape are resolved.
- Confidence rises by two because independent constructor, caller, palette-provider, DLPalette-mutator, DrawGlyph, and destructor evidence converge.
- Do not score higher: no original PDB/source declarations prove method/member names or getter `const`, and no source text proves whether declarations used an API macro or alternate palette-specific spelling.
- Support scores and managed C++ remain unchanged except the explicit UID00016I member-token synchronization required for consistency; post-refresh header audit confirms every support score listed in `Changed Files` remained stable.
- Preserve `CANONICAL_OWNER:00005V`, `EMITTER_UIDS:00005V`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_POSITION_OPTIONAL`, exact path/range, and `Nested:0`.

## Open Questions With Attempted Resolution

- **Was the original name `GetPalette` / `SetPalette`?** No symbol survives. Exact `DLPalette *` semantics and project naming make this the strongest concise pair. `GetBrushPalette` / `SetBrushPalette` are plausible but unsupported extra qualification. Resolve to `GetPalette` / `SetPalette` with explicit inference caveat.
- **Was the field `m_palette`?** No layout symbol survives. The field is exactly a current palette pointer, so `m_palette` is narrower and more accurate than `m_brushHandle`. Resolve to `m_palette`, retaining historical alias text.
- **Was the getter declared `const`?** ABI does not encode it. The body is read-only and getter style supports it. Recommend `const`, cap confidence, and do not treat it as symbol-proven.
- **Did the setter return the pointer?** EAX contains the argument after assignment, but no caller consumes it and adjacent setters are void. Resolve to `void` as source intent.
- **Does GrafPort own the palette?** Constructor nulls the field, destructor does not release it, and callers restore/clear it. Resolve as borrowed/non-owning.
- **Should target split into two children?** Exact pair grouping and nine-byte alignment are already clear; splitting adds no ownership/source benefit. Retain one item.
- **Should caller docs or PaletteLib own emission?** Receiver and direct field use prove GrafPort. Retain callers/providers as support only.
- No unresolved question blocks range, owner, emitter, score, formal C++, or generated emission; residual uncertainty is limited to textual identifiers and `const`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. Generated source, tracker, and coverage files are validator-owned derived artifacts.
- No manual tracker or coverage replacement text is recommended or permitted.
- Final waited generated refresh `000000008958` derived the `90/92` row and replaced the target Empty Emitter Marker with one exact body through the existing GrafPort route.

## Follow-Up Actions

- Supervisor-owned validation, execution, count, current path, move, and archive state are external to this artifact and are neither asserted nor directed here.
- Implementation and validators are complete; no accepted C01-C30 item remains.
- B004 itself performed no report execution, lifecycle, move, or archive command. Validation, execution, count, current path, move, and archive state remain external supervisor/validator-owned facts.
- Generated proof is complete: one UID000163 record/body under `NexusTK/render/GrafPort.cpp`, one `GetPalette` definition, one `SetPalette` definition, no target Empty Emitter Marker, one UID00016I record using `m_palette`, and zero `m_brushHandle` tokens; no manual generated edit occurred.
- No A-agent action, new target, split, or further binary research is required.

## Confidence

- Recommendation confidence: `92`.
- High-confidence facts: boundaries, bytes, ABI, all direct callers, `DLPalette *` type, borrowed lifetime, receiver class, owner/emitter, and source file.
- Medium-high inference: `GetPalette`, `SetPalette`, `m_palette`, parameter name, and getter `const`.
- The residual identifier uncertainty is explicitly preserved and does not justify retaining blank C++.

## Validator Results

- `000000008933`, `2026-07-12T23:17:16-04:00`, exit `0`, `ok: 1`: target UID000163 scoped apply; completion `90`, confidence `92`, autogen registry blank-to-block update; generated refresh deferred.
- `000000008934`, `2026-07-12T23:18:31-04:00`, exit `0`, `ok: 1`: `by-class/GrafPort.md`; generated refresh deferred. Seven pre-existing missing-reference warnings for UID0003XE/UID0003XB remained outside this callback.
- `000000008935`, `2026-07-12T23:19:05-04:00`, exit `0`, `ok: 1`: `by-file/GrafPort.md`; generated refresh deferred. Seven pre-existing missing-reference warnings for UID0003XB/UID0003XE remained outside this callback.
- `000000008936`, `2026-07-12T23:19:32-04:00`, exit `0`, `ok: 1`: UID000160 GrafPort aggregate; generated refresh deferred. Fourteen pre-existing missing-reference warnings, including UID0003XB/UID0003ZP/UID0003XD/UID0003XE, remained outside this callback.
- `000000008938`, `2026-07-12T23:19:58-04:00`, exit `0`, `ok: 1`: UID00016I DrawGlyph scoped apply; autogen registry updated and UID000163 reference indexed; generated refresh deferred.
- `000000008939`, `2026-07-12T23:20:27-04:00`, exit `0`, `ok: 1`: UID0001A6 appearance aggregate; GrafPort reference indexed; generated refresh deferred.
- `000000008940`, `2026-07-12T23:20:42-04:00`, exit `0`, `ok: 1`: `by-class/UserHairColorSelectListPane.md`; generated refresh deferred.
- `000000008941`, `2026-07-12T23:20:58-04:00`, exit `0`, `ok: 1`: `by-class/UserFaceColorSelectListPane.md`; generated refresh deferred.
- `000000008943`, `2026-07-12T23:21:11-04:00`, exit `0`, `ok: 1`: `by-class/BalloonObjectPane.md`; generated refresh deferred.
- `000000008944`, `2026-07-12T23:21:33-04:00`, exit `0`, `ok: 1`: UID0000YZ BalloonObjectPane aggregate; UID000163 reference indexed; generated refresh deferred. Two pre-existing missing-reference warnings for UID0003TN/UID0003Z4 remained outside this callback.
- `000000008945`, `2026-07-12T23:21:45-04:00`, exit `0`, `ok: 1`: `by-class/ColorStringChattingMessage.md`; generated refresh deferred.
- `000000008947`, `2026-07-12T23:22:01-04:00`, exit `0`, `ok: 1`: UID0002GH ColorStringChattingMessage draw child; generated refresh deferred.
- `000000008948`, `2026-07-12T23:22:17-04:00`, exit `0`: authorized final `--mode autogen --apply --wait-generated`; `generated_refresh: completed`, registry rebuilt, generated metadata refreshed.
- `000000008957`, `2026-07-12T23:26:21-04:00`, exit `0`, `ok: 1`: final UID00016I prose cleanup removed the two remaining literal historical opaque-member tokens; generated refresh deferred; lease released.
- `000000008958`, `2026-07-12T23:26:27-04:00`, exit `0`: final `--mode autogen --apply --wait-generated`; `generated_refresh: completed`, registry rebuilt, generated metadata and memory auto-coverage refreshed. Command `8948` remains the earlier successful waited refresh before the final prose cleanup.
- Read-only generated proof after `8958`: header command/timestamp match; UID000163 record count `1`; exact `DLPalette *GrafPort::GetPalette() const` count `1`; exact `void GrafPort::SetPalette(DLPalette *palette)` count `1`; target Empty Emitter Marker count `0`; UID00016I record count `1`; `m_brushHandle` count `0`; DrawGlyph callback uses `m_palette` once. The UID000163 generated body contains only one return and one assignment, proving no duplicate or fabricated ownership/lifetime behavior.
- Final report preflight read-only freshness proof: newer external generated header `000000008972` / `2026-07-12T23:27:46-04:00` preserved UID000163 count `1`, getter count `1`, setter count `1`, target empty-marker count `0`, UID00016I count `1`, and `m_brushHandle` count `0`. This newer validator-owned header is not a B004 command and introduces no implementation difference.
- Lease proof: each of the twelve by-* pages was leased immediately before its edit and released immediately after its scoped validator. Final shared lease report contains no B004 lease; an unrelated B003 Deque lease does not overlap this work.
- MCP read-only evidence calls succeeded against `supervisor_20260712`; no callback binary uncertainty required another MCP call.
- Unresolved callback errors: none. All warnings listed above were pre-existing reference-index diagnostics and did not concern UID000163 or the accepted support links.

## Changed Files

- Created during report-only phase and updated during callback: `tools/leaser/Agents/Agent-B004/research/000163-DrawContextBrushHandleHelpers-empty-emitter-source-quality.md`.
- Modified: `by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md` (`86/90 -> 90/92`, exact managed C++, full C01-C30 evidence).
- Modified without score/metadata changes: `by-class/GrafPort.md`.
- Modified without score/metadata changes: `by-file/GrafPort.md`.
- Modified without score/metadata/formal-C++ changes: `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md`.
- Modified without score/metadata changes and with only target-related `m_brushHandle -> m_palette` formal/prose synchronization: `by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md`.
- Modified without score/metadata/formal-C++ changes: `by-memory/0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md`.
- Modified without score/metadata/formal-C++ changes: `by-class/UserHairColorSelectListPane.md`.
- Modified without score/metadata/formal-C++ changes: `by-class/UserFaceColorSelectListPane.md`.
- Modified without score/metadata/formal-C++ changes: `by-class/BalloonObjectPane.md`.
- Modified without score/metadata/formal-C++ changes: `by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md`.
- Modified without score/metadata/formal-C++ changes: `by-class/ColorStringChattingMessage.md`.
- Modified without score/metadata/formal-C++ changes: `by-memory/0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md`.
- Validator-owned final generated refresh `000000008958` updated `auto-generated/NexusTK/render/GrafPort.cpp`, validator registry/coverage/tracker metadata, and other derived generated metadata. B004 made no manual generated, tracker, coverage, supervisor, registry, or project-level edit.
- Renamed/created by-* files: none. Report execution/lifecycle/move/archive commands by B004: none.

## Implementation Tracking Checklist

Initial report-only research:
- [x] Provenance headers and exact required headings supplied.
- [x] Current goal, target, generated marker, tracker snapshot, current goals/reports, and relevant support docs inspected.
- [x] MCP `idb_list`/`server_health` confirmed healthy evidence-time session `supervisor_20260712` before IDB work.
- [x] Exact getter/setter boundaries, bytes, ABI, padding, and successor/predecessor boundaries recorded.
- [x] Every getter/setter xref and all four containing callers classified.
- [x] Field type, constructor state, destructor behavior, direct uses, and borrowed lifetime resolved.
- [x] Source names, owner/emitter, source placement, split, score, metadata, and first-draft C++ resolved.
- [x] Positive/negative evidence, rejected alternatives, open questions, and confidence caps preserved.
- [x] C01-C30 ledger maps every claim to a destination, applied action, and validator/generated proof.
- [x] Exact target/support edit scope and generated expectation specified.
- [x] No forbidden by-* edit, lease, validator, generated edit/refresh, tracker/coverage edit, process management, execute_report, or lifecycle/move/archive command performed.

Implementation callback phase:
- [x] Supervisor accepted exact Gate 1 SHA `7DEF389ADB05B70F194117D408EC6BE39643272663F7B5BCC4B0CD8B646DC028` and C01-C30 scope.
- [x] Target leased immediately, changed `86/90 -> 90/92`, routing/nesting metadata preserved, exact evidence/C++ inserted, validator `8933` passed, and lease released.
- [x] `by-class/GrafPort.md` typed palette accessor/field synchronization applied without unrelated changes; validator `8934`; lease released.
- [x] `by-file/GrafPort.md` source-route/source-ready synchronization applied without unrelated changes; validator `8935`; lease released.
- [x] UID000160 GrafPort aggregate typed target row/lifetime evidence applied only; validator `8936`; lease released.
- [x] UID00016I DrawGlyph changed only target-related `m_brushHandle` to `m_palette` in formal/prose occurrences; validators `8938` and final literal-cleanup `8957`; leases released.
- [x] UID0001A6 stale generated-owner wording and slot-14/slot-13 install-clear facts corrected without score/C++ changes; validator `8939`; lease released.
- [x] Hair and face class pages synchronized to slot-14/slot-13 install-clear semantics without score/C++ changes; validators `8940`/`8941`; leases released.
- [x] BalloonObjectPane class and aggregate synchronized to exact save/install/restore facts without score/C++ changes; validators `8943`/`8944`; leases released.
- [x] ColorStringChattingMessage class and draw child synchronized to exact typed save/install/restore wording without score/C++ changes; validators `8945`/`8947`; leases released.
- [x] All unrelated managed blocks, metadata, support scores, historical evidence, and rejected alternatives preserved; post-refresh support header audit recorded above.
- [x] C01-C30 ledger, checklist, Validator Results, Changed Files, and current-state wording updated at report-level detail.
- [x] Final validator-owned refresh `8958` completed and verified one UID000163 body, no target Empty Emitter Marker, one getter, one setter, UID00016I `m_palette`, and zero `m_brushHandle` tokens.
- [x] Generated/tracker/coverage/supervisor/registry files remained manually unedited; all B004 leases released; report execution/lifecycle/move/archive state remains supervisor-owned.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000009011","destination_path":"executed-b-agent-research/B004/000163-DrawContextBrushHandleHelpers-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/000163-DrawContextBrushHandleHelpers-empty-emitter-source-quality.md","timestamp":"2026-07-12T23:36:27-04:00","uid":"000163"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
