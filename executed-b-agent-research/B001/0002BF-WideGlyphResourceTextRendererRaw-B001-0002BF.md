** TARGET-REPORT-UID:0002BF **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BF WideGlyphResourceTextRendererRaw Ownership / Split Research

## Finalized Recommendation

Assign `[UID:0002BF] 0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw` to `[UID:00007P] MapNamePane`.

This is a source-authored raw helper that IDA 9.1 still does not recognize as a function and that still has no live caller/table/vtable reference. However, the ownership evidence is now strong enough for a parent assignment: the helper is a `thiscall` 9x11 wide-glyph renderer, reads the glyph surface table from `this + 0x220`, and the immediately following `MapNamePane` constructor loads `9X11FONT.BIN` into exactly that class field (`this[136]`, offset `0x220`) while the destructor frees the same field. The closest assigned analogues are the UserStatusPane 9x11 glyph helpers, which use the same code shape and are owned by the class whose constructor loads the matching font slot.

Do not split or rename the target range. Keep it reconstructable as a raw helper, keep final C++ blank, and preserve the live-reachability caveat: no caller is proven. The aggregate `[UID:00022Z] 0x00503060-0x005031e1.UiAssetModeRectAndWideTextRawHelpers` should remain a non-emitting mixed inventory with blank parent; only `0002BF` has the private-field evidence needed for assignment.

Recommended target header edit:

```text
*** AUTOGEN_PARENT_UID:00007P | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended `auto-generated/-ag-memory-coverage.md` replacement row:

```markdown
| [UID:0002BF][0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw](by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md) | assigned | `00007P` |  | no | `auto-generated/NexusTK/map/MapNamePane.cpp` | `by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md` |  |
```

Recommended `by-memory/-coverage-report.md` replacement child row for the supervisor to apply:

```markdown
        - [UID:0002BF][0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw](by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md) 0x00503110-0x005031e1 | raw function | WideGlyphResourceTextRendererRaw : reconstructable : 87% : strong : B001-0002BF recommends direct parent [UID:00007P][MapNamePane](by-class/MapNamePane.md): live IDA still reports no function object/start xrefs/raw pointer hits/PE-level absolute-VA/RVA/relative references/MapName-or-MiniMapButton-adjacent vtable slot, but the exact source-authored 9x11 glyph helper is thiscall, uniquely reads the MapNamePane glyph-table field at this+0x220, matches the constructor's 9X11FONT.BIN load into this[136] at 0x0050329f and destructor cleanup of this[136], has exact unique bytes, matches the assigned UserStatusPane glyph-helper family shape, renders through SurfaceRenderCallbackTable slot dword_69B3E8, advances destination by 9, and retains unresolved live-reachability/C++ emission caveats.
```

Confidence:

| Claim | Confidence | Basis |
| --- | ---: | --- |
| Range and behavior are correct | 93 | IDA bytes/disassembly, prior A003 validation, exact body ending at `retn 0x10`, `0xcc` padding after `0x005031e1`. |
| Source-authored raw helper, not compiler/runtime | 91 | Complex UI rect setup, UTF-16 glyph loop, class field access, render callback dispatch. |
| Direct parent should be `MapNamePane` | 86 | Private field match at `this+0x220`, adjacent constructor/destructor ownership, assigned analogue family. |
| Live reachability is proven | 30 | Still no call/xref/table/vtable evidence; assignment is source-ownership inference, not proven executed path. |

## Scope And Current Documentation State

Target page:

- `[UID:0002BF] by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md`
- Current score: `COMPLETION:87`, `CONFIDENCE:91`
- Current parent: blank
- Current disposition: reconstructable raw source-authored helper, final C++ blank

Containing aggregate:

- `[UID:00022Z] by-memory/0x00503060-0x005031e1.UiAssetModeRectAndWideTextRawHelpers.md`
- Non-emitting split inventory, `RECONSTRUCTABLE:FALSE`, blank parent
- Children:
  - `[UID:0002BD] 0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper`
  - `[UID:0002BE] 0x005030c0-0x00503104.UiAssetModeRectWriteHelper`
  - `[UID:0002BF] 0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw`

No range split is needed. The target body starts at a conventional prologue at `0x00503110`, ends with `retn 0x10` at `0x005031de`, and the following bytes through `0x005031f0` are padding before the `MapNamePane` constructor.

## IDA Ground Truth

IDA MCP session:

- Database/session: `b001_nexustk`
- Image: `NexusTK.exe`
- Image base: `0x00400000`
- Hex-Rays available

Function discovery:

| Address | IDA status |
| --- | --- |
| `0x00503110` | No function object |
| `0x005031e1` | No function object |
| `0x005031f0` | Function `sub_5031F0`, size `0xd3` |
| `0x005032d0` | Function `sub_5032D0`, size `0x7d` |
| `0x00503350` | Function `sub_503350`, size `0x14f` |
| `0x005034a0` | Function `sub_5034A0`, size `0xd4` |
| `0x00503580` | Function `sub_503580`, size `0x9e` |

Direct reference checks:

- `xrefs_to 0x00503110`: none.
- `xrefs_to 0x00503060`: none.
- `xrefs_to 0x005030c0`: none.
- Section-aware absolute-VA, RVA, `E8/E9 rel32`, near conditional branch, and short conditional branch scans found no references to `0x00503110`, `0x00503060`, or `0x005030c0`.
- MapNamePane vtable heads at `0x0061e5b4`, `0x0061e600`, and `0x0061e630` have normal constructor/destructor/scalar-dtor data refs only; no raw helper slot points at the target.
- MiniMapButtonPane vtable heads at `0x0061e63c`, `0x0061e688`, and `0x0061e6b8` likewise have normal class refs only; no raw helper slot points at the target.

The negative reference result remains real. The recommendation does not claim a live caller.

## Target Behavior Evidence

IDA disassembly at `0x00503110` shows a complete stack-cookie protected helper:

```asm
00503110  push    ebp
00503111  mov     ebp, esp
00503113  sub     esp, 3Ch
00503116  mov     eax, ___security_cookie
00503121  mov     bl, [ebp+14h]
00503125  mov     esi, [ebp+8]
00503129  mov     edi, ecx
...
00503146  call    sub_4B7C50
0050315F  call    sub_4B7C50
00503164  movzx   eax, word ptr [esi]
00503170  cmp     ax, 20h
00503176  cmp     ax, 2Fh
0050317F  movsx   ecx, bl
00503188  lea     ecx, [ecx+ecx*4]
0050318B  lea     eax, [eax+ecx*2]
00503190  add     eax, 0FFFFFFD1h
00503193  imul    eax, 63h
00503196  add     eax, [edi+220h]
005031AB  call    dword_69B3E8
005031BC  call    sub_4B7E10
...
005031DE  retn    10h
```

Behavior summary:

- `ecx` is preserved as `edi`, so the helper is `thiscall`.
- Argument 1 is a UTF-16 string pointer.
- Arguments 2 and 3 are destination x/y coordinates.
- Argument 4 is a style/bank byte.
- Two `RectBounds`-like stack records are initialized: source `9 x 11`, destination `(x, y, x+9, y+11)`.
- The loop skips wide space `0x20` and slash `0x2f`.
- The glyph offset formula is `(codeUnit + style * 10 - 47) * 99 + *(this + 0x220)`.
- Rendering dispatches through `dword_69B3E8`, the Surface render callback slot.
- Destination advances by 9 pixels per code unit.

This is not compiler support code. It is a handwritten UI text/glyph renderer.

## MapNamePane Field Ownership Evidence

The immediately following constructor, `sub_5031F0`, is already documented as `MapNamePane`. Hex-Rays shows it installs the MapNamePane vtables, stores the singleton, initializes a resource context, and conditionally loads `9X11FONT.BIN`:

- `dword_69B4B4 = this`
- MapNamePane vtable writes to `*this`, `this[40]`, and `this[41]`
- `sub_457A60(this + 126)`
- `sub_4D02F0(&off_61E6C0, 0, this + 126)`
- `this[136] = sub_4BB120(&off_61682C, 0x63, v4)`

`this[136]` is byte offset `0x220`, exactly the field read by the target helper at `0x00503196`.

The destructor/cleanup function `sub_5032D0` confirms the same field has owned resource lifetime:

- Reads `v2 = this[136]`
- Calls `sub_516030` on the resource when non-null
- Stores `this[136] = sub_516170(v2)`
- Clears the `MapNamePane` singleton

This is the strongest ownership evidence in the record. The helper is not just adjacent to MapNamePane code; it consumes a private MapNamePane resource field whose constructor/destructor lifecycle is already documented.

The exact instruction bytes for `add eax, [edi+220h]` (`03 87 20 02 00 00`) occur only at `0x00503196` in the current IDA byte search. That does not prove ownership by itself, but it confirms this field access is not a broad repeated glyph-helper artifact.

## Analogue Family Evidence

Assigned 9x11 glyph renderers in the status-pane family have the same structure:

| Helper | Direct refs | Owner evidence |
| --- | ---: | --- |
| `[UID:0003AF] 0x005ba020-0x005ba0f1.UserStatusPaneGlyphTextDraw` | 10 paint-call refs | Reads `this[62]` / offset `0xf8`; constructor `0x005b83b0` loads `9X11FONT.BIN` into the same field. |
| `0x005bc010` UserStatusPane2 analogue | 10 paint-call refs | Same helper body and constructor font-field pattern. |
| `0x005bf3b0` OldUserStatusPane analogue | 9 paint-call refs | Same helper body and constructor font-field pattern. |

Hex-Rays decompilation of `0x005ba020` shows the same flow:

- Initialize source/destination rectangles.
- Loop over UTF-16 characters.
- Skip `0x20` and `0x2f`.
- Compute `99 * (char + 10 * style - 47)`.
- Add the class font-table field.
- Dispatch through `dword_69B3E8`.
- Advance the destination by 9 pixels.

The difference is reachability: the status-pane helpers have direct paint-method callers, while `0002BF` does not. That prevents a live-use claim for `0002BF`, but the source-ownership pattern is the same: a class-local helper reads the class-local 9X11 font table loaded by the class constructor.

## Documentation Evidence

Relevant existing documentation reviewed:

- `[UID:0002BF] WideGlyphResourceTextRendererRaw`: correctly records the raw body, no IDA function object, no xrefs, no pointer hits, no vtable slot, `this+0x220` font-field access, render callback dependency, and blank parent.
- `[UID:00022Z] UiAssetModeRectAndWideTextRawHelpers`: correctly treats the three raw helpers as a mixed non-emitting inventory and warns against absorbing the whole cluster into MapName/MiniMap without evidence.
- `[UID:00007P] MapNamePane`: documents constructor `0x005031f0`, destructor `0x005032d0`, render/update methods, singleton, resource setup, and `+0x220` cleanup.
- `[UID:0000L2] MapNamePane` by-file page: already at `86/86`, proposed source path `NexusTK/map/MapNamePane.cpp`, and ownership of the MapNamePane methods.
- `[UID:0001AL] MapNameAndMiniMapButtonPanes`: documents the MapName/MiniMapButton split inventory and keeps the preceding raw helper cluster outside that aggregate because no references were then known.
- `[UID:00008B] MiniMapButtonPane` and `[UID:0000LE] MiniMap`: no target field/ref evidence.
- `[UID:0003AF] UserStatusPaneGlyphTextDraw`: assigned analogue with the same renderer shape and class-owned 9X11 font field.
- `by-resource/user-status-resources.md` and `[UID:0003SB] CollectionReadOnlyData`: confirm `9X11FONT.BIN` is a shared UI numeric-font resource, not private to a single pane.

Existing docs are mostly accurate. The only change recommended here is the ownership conclusion for `0002BF`: prior documentation left parent blank because it required live reachability. B001 treats the class private-field lifecycle as enough for source ownership while keeping the no-caller caveat.

## Candidate Ownership Ranking

### 1. MapNamePane class `[UID:00007P]` - recommended

Evidence:

- Target is `thiscall` and uses `ecx` as object pointer.
- Target reads `this + 0x220`.
- MapNamePane constructor loads `9X11FONT.BIN` into `this[136]`, exactly offset `0x220`.
- MapNamePane destructor frees/clears `this[136]`.
- Target is immediately before the MapNamePane constructor and separated by only `0xcc` padding.
- The UserStatusPane glyph helpers establish a repeated source pattern: pane constructor owns `9X11FONT.BIN` field, pane-local helper reads the field, helper renders through `dword_69B3E8`.
- Direct parent rules favor the class over the broad file because this helper consumes a private class field.

Disconfirming evidence:

- No caller is known.
- IDA does not make the target a function.
- MapNamePane render method at `0x00503350` does not call the target in the current binary.
- No vtable/table slot points at the target.

Conclusion: assign as a retained/unreferenced private `MapNamePane` helper, not as a proven live render path.

### 2. Leave parent blank - rejected after deeper B-track inference

This remains defensible under a stricter "no live reference, no parent" rule. It is weaker here because the target has a precise class-field match to a documented constructor/destructor field. Keeping the page parentless would lose a concrete source-family relationship that is stronger than semantic adjacency.

### 3. New standalone MapName raw-helper source family - rejected

A possible future grouping could be something like `MapNameUiResourceTextHelpers`, containing raw helper code around `0x00503060-0x005031e1`. That is not recommended now:

- `0002BD` and `0002BE` still lack class-field, caller, or table evidence.
- No independent source file/table/string evidence points to a helper-only translation unit.
- `0002BF` is better modeled as a class-private helper because it reads `MapNamePane`'s owned resource field.

If a future source-discovery pass finds caller/table evidence for the three-helper cluster, the likely contents of such a source family would be small UI rectangle setup/write helpers plus the wide 9x11 glyph renderer used by MapName or neighboring UI asset-mode drawing. Current evidence supports only assigning `0002BF` to `MapNamePane`.

### 4. MiniMapButtonPane / MiniMap - rejected

The target sits before a mixed MapName/MiniMapButton code island, but:

- No MiniMapButton vtable slot or pointer references the helper.
- The target field offset `0x220` is explained by MapNamePane's font resource field.
- No MiniMapButton constructor/destructor evidence ties to the target.
- No `MMAPBUT` or minimap-specific resource evidence appears in the target.

### 5. UserStatusPane or status resources - rejected as owner, accepted as analogue

`9X11FONT.BIN` is shared, and the status-pane helpers are excellent behavioral analogues. They are not owners of this address:

- Their helper addresses are separate (`0x005ba020`, `0x005bc010`, `0x005bf3b0`).
- Their fields are offset `0xf8`, not `0x220`.
- Their direct callers are in status-pane paint methods, not MapName.

### 6. MainMenuPane - rejected

The prior MainMenu packet/dialog helper aggregate ends before this raw-helper cluster and is separated by padding. It has no direct target reference, no matching private font field, and no source-family evidence for the wide glyph helper.

### 7. Surface / EPF / RectBounds systems - rejected as direct owners

`dword_69B3E8`, `sub_4B7C50`, and `sub_4B7E10` are dependencies used by many UI render paths. They explain how rendering works, not who owns the helper.

### 8. Compiler/runtime support - rejected

The stack cookie prologue/epilogue is compiler-generated, but the body is a handwritten renderer with UI resource semantics. The source owner is application UI code.

## Split And Repair Analysis

No child split is required.

Range boundaries:

- Start `0x00503110`: canonical prologue and target body start.
- End `0x005031e1`: immediately after `retn 0x10`.
- `0x005031e1-0x005031f0`: padding before `MapNamePane` constructor.

No stale filename repair is required. The current name `WideGlyphResourceTextRendererRaw` is accurate enough. A more owner-specific name such as `MapNamePaneWideGlyphResourceTextRendererRaw` would be justified after parent assignment, but renaming is not required and would create avoidable broad-reference churn.

No aggregate parent repair is recommended. `[UID:00022Z]` remains a mixed inventory because its other children do not inherit this target's private-field proof.

## Validation

Target page validator dry-run before this report:

> Executable block R001 was removed from this report and preserved verbatim in [0002BF-WideGlyphResourceTextRendererRaw-B001-0002BF-removed.md](0002BF-WideGlyphResourceTextRendererRaw-B001-0002BF-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
ok 0002BF UID header exists
autogen_report_noop auto-generated/-ag-memory-coverage.md unchanged
```

No by-memory coverage file was edited by B001.

## Concrete Next Actions

1. Supervisor should set `AUTOGEN_PARENT_UID:00007P` on `by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md`.
2. Supervisor should update/regenerate the memory coverage row using the exact `auto-generated/-ag-memory-coverage.md` row above.
3. Supervisor should replace the child row in `by-memory/-coverage-report.md` using the exact row above.
4. Optional but not required: append a short note to the target page stating that the parent assignment is based on private-field lifecycle evidence, while live reachability remains unresolved.
5. Do not assign siblings `0002BD` or `0002BE` to MapNamePane from this report alone; they require separate evidence.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002BF-WideGlyphResourceTextRendererRaw-B001-0002BF.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002BF"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002BF-WideGlyphResourceTextRendererRaw-B001-0002BF-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002BF-WideGlyphResourceTextRendererRaw-B001-0002BF.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002BF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
