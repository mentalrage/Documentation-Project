** TARGET-REPORT-UID:0001GG **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B001 Research Report: UID 0001GG SharedBooleanVirtualStubs

Target: `by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md`

Assignment: current Goal 2 no-owner/non-emitting source-quality reanalysis for live generated row `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:TRUE`.

Report-only constraint followed: this report does not edit any by-* target documentation, generated source, or coverage report. All changes below are recommended supervisor edits.

## Heuristic / Inference Reanalysis And Validation

### Current target state checked

- Target page metadata currently records:
  - `UID: 0001GG`
  - `COMPLETION: 86`
  - `CONFIDENCE: 89`
  - `CANONICAL_OWNER: NONE`
  - `RECONSTRUCTABLE: TRUE`
  - blank `EMITTER_UIDS`
  - blank `CPP`
- Live generated coverage row in `auto-generated/-ag-memory-coverage.md` currently treats the page as no-owner/non-emitting:
  - `| [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md` |  |`
- `by-memory/-coverage-report.md` is stale for this row. It still gives the range as `0x0055c1b0-0x0055c1c2`, labels the source family as `SystemMessageBooleanVirtuals`, and lists `76%`.

### Binary evidence revalidated this session

IDA MCP was attempted for the local endpoint at `http://127.0.0.1:13337/mcp`, but the endpoint was not reachable in this session. I therefore used the read-only local PE image `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for direct byte, section, dword, and pointer scans. This is independent binary evidence, not a copy from old reports.

The PE image base is `0x00400000`. The relevant sections map the target code into `.text` and the vtable/runtime pointer cells into `.rdata`:

| Section | VA | Virtual size | Raw pointer | Raw size |
|---|---:|---:|---:|---:|
| `.text` | `0x00001000` | `0x0020b66c` | `0x00000400` | `0x0020b800` |
| `.rdata` | `0x0020d000` | `0x0005f0be` | `0x0020bc00` | `0x0005f200` |
| `.data` | `0x0026d000` | `0x0002fe24` | `0x0026ae00` | `0x0000d800` |

Relevant code bytes:

| Address | Bytes | Meaning |
|---|---|---|
| `0x0055c1a0` | `5d c2 04 00 cc cc cc cc cc cc cc cc cc cc cc cc` | predecessor tail plus padding before target |
| `0x0055c1b0` | `b0 01 c3 cc cc cc cc cc cc cc cc cc cc cc cc cc` | three-byte return-true body followed by `0xcc` padding |
| `0x0055c1c0` | `32 c0 c3 cc cc cc cc cc cc cc cc cc cc cc cc cc` | three-byte return-false body followed by `0xcc` padding |
| `0x0055c1d0` | `56 8b f1 8b 06 8b 00 ff d0 ...` | next real function body starts after padding |

This confirms the target is exactly two independent tiny function bodies:

```asm
0x0055c1b0: mov al, 1
0x0055c1b2: ret

0x0055c1c0: xor al, al
0x0055c1c2: ret
```

Selected pointer cells directly verified from the image:

| Address | Value | Interpretation |
|---|---:|---|
| `0x006235a4` | `0x0055c1c0` | `ScreenEffecter` vtable first boolean slot returns false |
| `0x006235c4` | `0x0055c1b0` | `PixelEffecter` vtable first boolean slot returns true |
| `0x00623cf8` | `0x0055c1b0` | later effecter-family vtable first slot returns true |
| `0x0062d6b8` | `0x0055c1b0` | `HeaderSystemMessage` marker slot returns true |
| `0x0062d6bc` | `0x0055c1c0` | `HeaderSystemMessage` paired marker slot returns false |
| `0x0062d6dc` | `0x0055c1c0` | `FooterSystemMessage` marker slot returns false |
| `0x0062d6e0` | `0x0055c1b0` | `FooterSystemMessage` paired marker slot returns true |
| `0x0062d700` | `0x0055c1c0` | `ColorStringSystemMessage` marker slot returns false |
| `0x0062d704` | `0x0055c1c0` | `ColorStringSystemMessage` paired marker slot returns false |
| `0x00637548` | `0x0055c1b0` | runtime/read-only table true-stub pointer cell |
| `0x0063754c` | `0x0055c1b0` | runtime/read-only table true-stub pointer cell |

Raw VA pointer scan results:

- `0x0055c1b0` appears as a raw pointer value in 28 `.rdata` cells:
  - `0x006235c4`, `0x006235e8`, `0x006235ec`, `0x00623694`, `0x00623698`, `0x00623740`, `0x00623744`, `0x006237ec`, `0x006237f0`, `0x00623898`, `0x0062389c`, `0x0062394c`, `0x006239f4`, `0x00623a9c`, `0x00623b44`, `0x00623be4`, `0x00623c08`, `0x00623c2c`, `0x00623c58`, `0x00623cf8`, `0x0062d6b8`, `0x0062d6e0`, `0x00637548`, `0x0063754c`, `0x0063757c`, `0x0063758c`, `0x00637598`, `0x006375a4`
- `0x0055c1c0` appears as a raw pointer value in 32 `.rdata` cells:
  - `0x006235a4`, `0x006235a8`, `0x006235ac`, `0x006235c8`, `0x006235cc`, `0x006235f0`, `0x0062369c`, `0x00623748`, `0x006237f4`, `0x006238a0`, `0x00623944`, `0x00623948`, `0x006239ec`, `0x006239f0`, `0x00623a94`, `0x00623a98`, `0x00623b3c`, `0x00623b40`, `0x00623be8`, `0x00623bec`, `0x00623c0c`, `0x00623c10`, `0x00623c30`, `0x00623c34`, `0x00623c50`, `0x00623c54`, `0x00623cfc`, `0x00623d00`, `0x0062d6bc`, `0x0062d6dc`, `0x0062d700`, `0x0062d704`

Direct branch scan found one direct `E8` call target to `0x0055c1b0` at `0x005c8489`, and no direct branch to `0x0055c1c0`. The target page already identifies the direct true-stub call as a CRT pre-initialization artifact. I found no evidence that this call makes a game source owner.

### Existing current documentation checked

The following current docs were reviewed as evidence, not treated as authoritative without revalidation:

- `by-file/SystemMessagePanes.md` owns `NexusTK/social/SystemMessagePanes.cpp`, records the system-message panes/classes, and already notes the boolean helper addresses as shared but not final source-ready.
- `by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md` records the system-message pane aggregate and header/footer/color string message behavior around header marker append, footer marker append, colored text append, clone, insert, and prune paths.
- `by-class/HeaderSystemMessage.md`, `by-class/FooterSystemMessage.md`, and `by-class/ColorStringSystemMessage.md` record the vtable pointer patterns around `0x0062d6a8`, `0x0062d6cc`, and `0x0062d6f0`.
- `by-memory/0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData.md`, `by-memory/0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData.md`, and `by-memory/0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData.md` record exact child vtable data with owner/emitter class pages.
- `by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md` records the mixed system-message `.rdata` area and exact child vtable pages.
- `by-file/Effects.md`, `by-class/ScreenEffecter.md`, `by-class/PixelEffecter.md`, `by-class/CloudFilterEffecter.md`, `by-type/by-vtable/ScreenEffecterVtableFamily.md`, `by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md`, and `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md` record the effecter-family use.
- `by-memory/0x00503e90-0x00503ecd.MapPaneFindActiveEffect.md` and active generated `auto-generated/NexusTK/map/MapPane.cpp` record the source-facing effecter first-slot inference as `ScreenEffecter::IsPixelEffecter()` in `MapPane::FindActivePixelEffecter()`.
- `by-memory/0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual.md` is a useful contrast: a tiny folded virtual body can be owned by `SystemMessagePanes` when all known source use is within that one family. UID `0001GG` does not meet that condition because the same bodies are shared with Effects and CRT/runtime artifacts.
- `by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md` is a useful negative contrast: shared MSVC scalar deleting destructor glue is `RECONSTRUCTABLE:FALSE`. UID `0001GG` should not be reclassified that way because these true/false returns represent source-level virtual predicate semantics in game class vtables even though the executable bodies are folded.
- `by-memory/0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail.md` covers the `0x0063506c-0x00638600` CRT/type/assert/math/bootstrap tables that contain the later `0x00637548` and `0x0063754c` true-stub pointers and additional true-stub pointer-valued cells at `0x0063757c`, `0x0063758c`, `0x00637598`, and `0x006375a4`.

### Candidates considered

#### Candidate A: keep no-owner/non-emitting folded virtual page

This is the recommended classification.

Evidence:

- The two code bodies are valid source-level constant virtual behavior: `return true` and `return false`.
- The exact executable addresses are shared by unrelated source families:
  - `SystemMessagePanes` marker/color-entry vtables.
  - `Effects`/`ScreenEffecter` vtable family.
  - CRT pre-initialization call and runtime/read-only table pointer cells.
- The same physical true/false body cannot honestly be assigned to a single source file without hiding cross-family ownership.
- Source reconstruction should model the behavior at class declaration/override sites, not by emitting a standalone function named after an executable artifact.
- Current `RECONSTRUCTABLE:TRUE` is still appropriate because source declarations should exist. The no-emitter state is about this folded physical page, not about source behavior being unreconstructable.

Before/after recommendation:

- Keep `COMPLETION: 86`.
- Keep `CONFIDENCE: 89`.
- Keep `CANONICAL_OWNER: NONE`.
- Keep `RECONSTRUCTABLE: TRUE`.
- Keep blank `EMITTER_UIDS`.
- Keep blank `CPP`.

Reason to keep score below final-source threshold: the physical behavior is fully known, but the exact original per-class method names and declaration placement are not proven enough for final C++ emission. The page is above 85 because the binary behavior, bounds, and cross-family data-use evidence are strong.

#### Candidate B: assign to `SystemMessagePanes` only

Rejected.

The `HeaderSystemMessage`, `FooterSystemMessage`, and `ColorStringSystemMessage` vtables definitely reference these bodies, but effecter-family vtables also definitely reference the same bodies. A `SystemMessagePanes` owner would be a source-placement overreach. It would also fail to account for the `ScreenEffecter` first-slot predicate consumed by `MapPane::FindActivePixelEffecter()`.

#### Candidate C: assign to `Effects` / `ScreenEffecterVtableFamily` only

Rejected.

The effecter-family use is definite, especially the base false and derived true first-slot pattern around `0x006235a4`/`0x006235c4` and the `MapPane` consumer. However, the system-message vtable pointers are equally definite. `ScreenEffecterVtableFamily` owns the effecter vtable source placement, not the system-message marker vtables or CRT/runtime table artifacts.

#### Candidate D: give multiple emitters, such as `0000OE,0000IZ`

Rejected for this physical page.

Multiple emitters would be reasonable for some shared data when the generated source has a stable duplication or declaration strategy. Here it would imply emitting the same executable folded helper through both `SystemMessagePanes.cpp` and `Effects.cpp`, which would invent a source construct not supported by the evidence. The source-level constructs are class virtual declarations/overrides with trivial returns, not a global helper shared between files.

The better route is:

- Keep UID `0001GG` as no-owner/non-emitting physical folded evidence.
- Add descriptive per-class virtual slot documentation to the owning class/vtable pages.
- Only emit class declarations/overrides when the class docs have source-ready method names and C++ placement.

#### Candidate E: split into true and false child pages

Rejected for now.

The code bodies are physically distinct starts, and a future split would be technically possible:

- `0x0055c1b0-0x0055c1b3`: folded return-true virtual body.
- `0x0055c1c0-0x0055c1c3`: folded return-false virtual body.

However, splitting does not solve the ownership problem. Both child bodies remain shared by system-message, effecter, and runtime contexts. The exact source shape should be per-class slot declarations, not two new parentless physical helper pages. A split would add two ambiguous rows without improving generated C++ quality.

#### Candidate F: route through runtime/CRT docs

Rejected.

The direct call at `0x005c8489` to `0x0055c1b0` and later pointer cells at `0x00637548`, `0x0063754c`, `0x0063757c`, `0x0063758c`, `0x00637598`, and `0x006375a4` are real. Their location in the MSVC runtime read-only data tail supports treating them as runtime/startup artifacts. They do not outweigh the game vtable uses and do not create a CRT source owner for the game virtual predicates.

#### Candidate G: reclassify `RECONSTRUCTABLE:FALSE`

Rejected.

Unlike scalar deleting destructor wrappers or pure compiler runtime tables, the bodies implement source-visible virtual predicate results used in game vtables. The physical page should not emit code, but the behavior should be reflected through class-level source. Therefore `RECONSTRUCTABLE:TRUE` is still the correct metadata.

### Best source-name and source-placement inferences

These names are descriptive best guesses, not proven original spellings.

#### Physical folded page names

Recommended physical-page descriptive names:

- `0x0055c1b0`: `SharedReturnTrueVirtualStub` or `FoldedReturnTrueVirtualStub`.
- `0x0055c1c0`: `SharedReturnFalseVirtualStub` or `FoldedReturnFalseVirtualStub`.
- Existing page name `SharedBooleanVirtualStubs` remains acceptable because it describes the physical artifact rather than claiming a source symbol.

#### System-message marker slots

The current vtable pattern supports a stronger source-quality inference than generic "boolean virtual":

| Class | Vtable slot `+0x0c` | Vtable slot `+0x10` |
|---|---|---|
| `HeaderSystemMessage` | true via `0x0055c1b0` | false via `0x0055c1c0` |
| `FooterSystemMessage` | false via `0x0055c1c0` | true via `0x0055c1b0` |
| `ColorStringSystemMessage` | false via `0x0055c1c0` | false via `0x0055c1c0` |

Best descriptive inference:

- Slot `+0x0c` behaves like `IsHeaderMarker()`.
- Slot `+0x10` behaves like `IsFooterMarker()`.

This inference is supported by the class names, the complementary Header/Footer true/false pattern, and the neutral ColorString false/false pattern. It remains below final original-name confidence because no source names or direct caller decompilation for these exact slots were available in this session.

#### Effects / ScreenEffecter slots

The first effecter vtable boolean slot is already consumed by `MapPane::FindActivePixelEffecter()` in active generated C++:

```cpp
ScreenEffecter *MapPane::FindActivePixelEffecter()
{
    for (int index = 0; index < m_screenEffecterCount; ++index) {
        ScreenEffecter *effecter = m_screenEffecters[index];
        if (effecter->IsPixelEffecter()) {
            return effecter;
        }
    }
    return nullptr;
}
```

Best descriptive inference:

- The first effecter boolean slot behaves like `IsPixelEffecter()` or `UsesPrimaryEffectPass()`.
- The generated `MapPane.cpp` currently uses `IsPixelEffecter()`, so support docs should align to that descriptive name unless later evidence proves an original spelling.

The other nearby effecter boolean slots used by `ScreenEffecter::AreAllEffectsComplete` remain less nameable. They should be documented as state/progress predicates until stronger call-site evidence proves original names.

### First-draft C++ / no-code proof

No standalone C++ should be emitted for UID `0001GG`.

Precise no-code proof:

1. The physical page contains only two tiny constant-return functions:
   - `bool folded_true() { return true; }`
   - `bool folded_false() { return false; }`
2. The address identity of those functions is an executable-level folding result. It spans unrelated source families and runtime/startup artifacts.
3. A source file cannot contain one honest function for `0x0055c1b0` or `0x0055c1c0` that simultaneously belongs to `SystemMessagePanes`, `Effects`, and CRT runtime tables.
4. C++ source should instead express per-class virtual methods, for example:

```cpp
// Descriptive only, not final original spelling.
bool HeaderSystemMessage::IsHeaderMarker() const { return true; }
bool HeaderSystemMessage::IsFooterMarker() const { return false; }
bool FooterSystemMessage::IsHeaderMarker() const { return false; }
bool FooterSystemMessage::IsFooterMarker() const { return true; }
bool ColorStringSystemMessage::IsHeaderMarker() const { return false; }
bool ColorStringSystemMessage::IsFooterMarker() const { return false; }

bool ScreenEffecter::IsPixelEffecter() const { return false; }
bool PixelEffecter::IsPixelEffecter() const { return true; }
```

Those examples belong in class/file docs once names and declaration placement are source-ready. They should not be inserted into UID `0001GG` as `CPP`.

### Remaining blockers

- IDA MCP was not available in this session, so no fresh decompiler call-site inspection could be performed for system-message marker slot consumers.
- Exact original source names for the system-message marker predicates are still unproven. `IsHeaderMarker()` and `IsFooterMarker()` are high-probability descriptive names, not source-name confirmations.
- Exact original source name for the effecter first predicate remains not proven. The best current descriptive name is `IsPixelEffecter()` because active generated `MapPane.cpp` already uses it.
- The runtime/startup pointer table at `0x006375xx` needs no source owner, but a future IDA session could label the exact MSVC table role more specifically.

## Recommended by-* Document Changes

### 1. Target page metadata

File: `by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md`

Recommended metadata: no metadata change.

Keep:

```yaml
COMPLETION: 86
CONFIDENCE: 89
CANONICAL_OWNER: NONE
RECONSTRUCTABLE: TRUE
EMITTER_UIDS:
CPP:
```

Reason: this is the correct current source-quality state for a reconstructable but non-emitting folded physical page.

### 2. Target page status prose

File: `by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md`

Replace the current final status bullet that says the page is reconstructable but no single owner with this exact prose:

```markdown
- Reconstructable: true as source-level constant virtual behavior, but this exact executable page is compiler/linker-folded across SystemMessagePanes marker/color-entry slots, Effects/ScreenEffecter slots, and MSVC runtime startup/read-only-table use. Keep `CANONICAL_OWNER:NONE`, generated C++ blank, and `EMITTER_UIDS` empty; final source should model per-class virtual declarations/overrides through the owning class/file pages rather than emitting this physical helper as a standalone function.
```

### 3. Target page evidence notes

File: `by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md`

Add this bullet under the existing evidence notes:

```markdown
- 2026-06-18 B001 local PE check of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` independently confirms the exact target bounds and folded-body evidence: `0x0055c1b0` bytes `b0 01 c3` (`return true`), `0x0055c1c0` bytes `32 c0 c3` (`return false`), `0xcc` padding through the successor start at `0x0055c1d0`, effecter vtable refs at `0x006235a4`, `0x006235c4`, and `0x00623cf8`, system-message vtable refs at `0x0062d6b8`, `0x0062d6bc`, `0x0062d6dc`, `0x0062d6e0`, `0x0062d700`, and `0x0062d704`, and runtime/read-only true-stub pointer cells at `0x00637548`, `0x0063754c`, `0x0063757c`, `0x0063758c`, `0x00637598`, and `0x006375a4`. A raw pointer scan found 28 cells containing `0x0055c1b0` and 32 cells containing `0x0055c1c0`; a direct branch scan found only one direct `E8` hit to the true stub at `0x005c8489`, consistent with the existing CRT pre-initialization artifact note.
```

### 4. Target page reconstruction note

File: `by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md`

Add this note after the evidence notes or in the recommendations section:

```markdown
- Source-placement inference: keep the physical page named descriptively as `SharedBooleanVirtualStubs`. The true body can be described as `SharedReturnTrueVirtualStub`/`FoldedReturnTrueVirtualStub`, and the false body as `SharedReturnFalseVirtualStub`/`FoldedReturnFalseVirtualStub`, but these are executable-artifact descriptions rather than source symbols. For SystemMessagePanes, the best current descriptive class-level names are marker predicates at vtable slots `+0x0c` and `+0x10`, behaving like `IsHeaderMarker()` and `IsFooterMarker()`. For Effects, the first `ScreenEffecter` boolean slot is best described as `IsPixelEffecter()` or `UsesPrimaryEffectPass()`, with active generated `MapPane.cpp` currently using `IsPixelEffecter()`. Do not emit C++ from this page until those class-level declarations are represented in their owning source docs.
```

### 5. HeaderSystemMessage class page

File: `by-class/HeaderSystemMessage.md`

Recommended metadata: no metadata change required.

Replace any generic "true/false boolean virtual" method wording for the `0x0055c1b0` and `0x0055c1c0` rows with:

```markdown
| `0x0055c1b0-0x0055c1b3` | inferred `IsHeaderMarker` virtual | Returns true for the marker identity slot at vtable `+0x0c`. Descriptive name inferred from the Header true / Footer false / ColorString false vtable pattern; the body is folded with Effects and runtime uses in [UID:0001GG]. |
| `0x0055c1c0-0x0055c1c3` | inferred `IsFooterMarker` virtual | Returns false for the paired marker identity slot at vtable `+0x10`. Descriptive name inferred from the Header false / Footer true / ColorString false vtable pattern; the body is folded with Effects and runtime uses in [UID:0001GG]. |
```

In the vtable layout, use these exact row descriptions for the relevant slots:

```markdown
| `+0x0c` | `0x0055c1b0` | Inferred `IsHeaderMarker()` true slot; folded body [UID:0001GG]. |
| `+0x10` | `0x0055c1c0` | Inferred `IsFooterMarker()` false slot; folded body [UID:0001GG]. |
```

### 6. FooterSystemMessage class page

File: `by-class/FooterSystemMessage.md`

Recommended metadata: no metadata change required.

Replace any generic "true/false boolean virtual" method wording for the `0x0055c1b0` and `0x0055c1c0` rows with:

```markdown
| `0x0055c1c0-0x0055c1c3` | inferred `IsHeaderMarker` virtual | Returns false for the marker identity slot at vtable `+0x0c`. Descriptive name inferred from the Header true / Footer false / ColorString false vtable pattern; the body is folded with Effects and runtime uses in [UID:0001GG]. |
| `0x0055c1b0-0x0055c1b3` | inferred `IsFooterMarker` virtual | Returns true for the paired marker identity slot at vtable `+0x10`. Descriptive name inferred from the Header false / Footer true / ColorString false vtable pattern; the body is folded with Effects and runtime uses in [UID:0001GG]. |
```

In the vtable layout, use these exact row descriptions for the relevant slots:

```markdown
| `+0x0c` | `0x0055c1c0` | Inferred `IsHeaderMarker()` false slot; folded body [UID:0001GG]. |
| `+0x10` | `0x0055c1b0` | Inferred `IsFooterMarker()` true slot; folded body [UID:0001GG]. |
```

### 7. ColorStringSystemMessage class page

File: `by-class/ColorStringSystemMessage.md`

Recommended metadata: no metadata change required.

Replace the generic false boolean virtual row:

```markdown
| `0x0055c1c0-0x0055c1c3` | false boolean virtual | Returns false; vtable slot used by ColorStringSystemMessage and several related message/effecter classes. |
```

with:

```markdown
| `0x0055c1c0-0x0055c1c3` | inferred marker identity false virtuals | Returns false for both marker identity slots: vtable `+0x0c` inferred `IsHeaderMarker()` and vtable `+0x10` inferred `IsFooterMarker()`. Descriptive names are inferred from the Header/Footer/ColorString vtable pattern; the folded body is shared with Effects and runtime uses in [UID:0001GG]. |
```

In the vtable layout, use these exact row descriptions for the relevant slots:

```markdown
| `+0x0c` | `0x0055c1c0` | Inferred `IsHeaderMarker()` false slot; folded body [UID:0001GG]. |
| `+0x10` | `0x0055c1c0` | Inferred `IsFooterMarker()` false slot; folded body [UID:0001GG]. |
```

### 8. SystemMessagePanes support docs

Files:

- `by-file/SystemMessagePanes.md`
- `by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md`
- `by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md`
- `by-memory/0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData.md`
- `by-memory/0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData.md`
- `by-memory/0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData.md`

Recommended metadata: no metadata changes required.

Add or incorporate this support note where those docs currently discuss the shared boolean slots:

```markdown
- B001 source-placement update for [UID:0001GG]: the system-message vtable pattern supports descriptive marker identity predicates rather than generic boolean virtual names. Slot `+0x0c` behaves like `IsHeaderMarker()` (`HeaderSystemMessage` true, `FooterSystemMessage` false, `ColorStringSystemMessage` false). Slot `+0x10` behaves like `IsFooterMarker()` (`HeaderSystemMessage` false, `FooterSystemMessage` true, `ColorStringSystemMessage` false). These names remain inferred/descriptive; the folded physical true/false bodies are also used by the Effects/ScreenEffecter family and CRT/runtime tables, so [UID:0001GG] must remain no-owner/non-emitting.
```

### 9. Effects / ScreenEffecter support docs

Files:

- `by-file/Effects.md`
- `by-class/ScreenEffecter.md`
- `by-class/PixelEffecter.md`
- `by-type/by-vtable/ScreenEffecterVtableFamily.md`
- `by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md`
- `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md`
- `by-memory/0x00503e90-0x00503ecd.MapPaneFindActiveEffect.md`

Recommended metadata: no metadata changes required.

Add this support note to `by-type/by-vtable/ScreenEffecterVtableFamily.md` after the existing `MapPane` first-slot discussion, and incorporate equivalent detail in the related effecter docs when they next receive evidence updates:

```markdown
- B001 source-placement update for [UID:0001GG]: the physical true/false bodies used by the effecter first boolean slot are folded with system-message marker predicates and runtime/startup tables. Names such as `IsPixelEffecter()` or `UsesPrimaryEffectPass()` should be treated as descriptive class-level slot names; active generated `MapPane.cpp` currently uses `IsPixelEffecter()`. Do not route [UID:0001GG] through `Effects.cpp` as a standalone helper. Keep source emission at the class/vtable level once method declarations are final enough.
```

### 10. MSVC runtime read-only tail support doc

File: `by-memory/0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail.md`

Recommended metadata: no metadata change required.

Add this note under the `0x0063506c-0x00638600` CRT/type/assert/math/bootstrap table discussion:

```markdown
- B001 local PE scan for [UID:0001GG] found true-stub pointer-valued cells at `0x00637548`, `0x0063754c`, `0x0063757c`, `0x0063758c`, `0x00637598`, and `0x006375a4` inside this runtime/read-only tail. Treat these as CRT/runtime table artifacts; they do not make the folded game virtual body runtime-owned and do not justify emitting C++ from [UID:0001GG].
```

### 11. `wave3_data_issues.md`

Recommended metadata: not applicable.

Replace the current line:

```markdown
- HeaderSystemMessage and FooterSystemMessage vtables use shared tiny boolean helpers at 0x0055c1b0 and 0x0055c1c0; active generated files do not expose those slots under the marker classes.
```

with:

```markdown
- HeaderSystemMessage, FooterSystemMessage, and ColorStringSystemMessage vtables use shared folded boolean helpers at `0x0055c1b0` and `0x0055c1c0`. Best current descriptive inference is a pair of marker identity predicates: slot `+0x0c` behaves like `IsHeaderMarker()` (`HeaderSystemMessage` true, `FooterSystemMessage` false, `ColorStringSystemMessage` false) and slot `+0x10` behaves like `IsFooterMarker()` (`FooterSystemMessage` true, `HeaderSystemMessage` false, `ColorStringSystemMessage` false). Active generated files do not expose those slots under the marker classes, and the physical folded helper page [UID:0001GG] should stay no-owner/non-emitting until class-level virtual declarations are source-ready.
```

### 12. `by-project-structure/proposed-source-tree.md`

Recommended change: none.

Current state already uses the correct target range and generic folded-stub label:

```markdown
- [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](../by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) - SharedBooleanVirtualStubs
```

No supervisor edit is required here.

### 13. `auto-generated/-ag-memory-coverage.md`

Recommended manual change: none.

The live generated row already correctly reports no-owner/non-emitting state for UID `0001GG`. If the supervisor applies metadata/prose changes and regenerates auto-generated coverage, this row should remain no-owner with blank emitters.

### 14. Project unresolved/generated source

Recommended manual change: none.

Do not hand-edit generated `auto-generated/NexusTK/*` files or `project-level/-unresolved.md`. If class-level virtual declarations are later promoted to C++, they should be added through the owning class/file documentation and regenerated through the normal tooling.

## by-memory/-coverage-report.md Pending Supervisor Change

The memory coverage row should be changed. The current row is stale because it:

- uses an end address of `0x0055c1c2` instead of `0x0055c1c3`;
- implies `SystemMessageBooleanVirtuals` source ownership;
- has stale `76%` scoring;
- does not mention effecter-family and runtime/startup sharing.

Replace the current row:

```markdown
    - [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) 0x0055c1b0-0x0055c1c2 | shared virtual stubs | SystemMessageBooleanVirtuals : reconstructable : 76% : strong : Shared/folded boolean virtual stubs; IDA confirms three-byte true/false bodies, no callees, padding boundaries, and system-message plus effecter vtable data refs.
```

with this exact replacement row:

```markdown
    - [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) 0x0055c1b0-0x0055c1c3 | shared folded virtual stubs | SharedBooleanVirtualStubs : reconstructable : 86% : strong : Current B001 reanalysis keeps CANONICAL_OWNER NONE and blank emitters because the two three-byte return-true/return-false bodies are folded across SystemMessagePanes marker/color-entry vtables, Effects/ScreenEffecter vtables, and MSVC runtime startup/read-only table use; local PE bytes confirm exact true stub, inter-body padding, false stub, successor padding, direct branch hit only from CRT preinitialization, 28 raw true-stub pointer cells, and 32 raw false-stub pointer cells. Source output should be per-class virtual declarations/overrides, not a standalone emitted helper.
```

## Validation Needed

After applying the recommended supervisor edits, run file-level validation for each edited by-* document. Use PowerShell from the repository root `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0001GG-SharedBooleanVirtualStubs-current-no-owner-reanalysis-removed.md](0001GG-SharedBooleanVirtualStubs-current-no-owner-reanalysis-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor edits support reports that the validator accepts as file targets, also run:

> Executable block R002 was removed from this report and preserved verbatim in [0001GG-SharedBooleanVirtualStubs-current-no-owner-reanalysis-removed.md](0001GG-SharedBooleanVirtualStubs-current-no-owner-reanalysis-removed.md). The archived block is non-authoritative and must not be executed.

Then refresh and validate generated coverage/source outputs:

> Executable block R003 was removed from this report and preserved verbatim in [0001GG-SharedBooleanVirtualStubs-current-no-owner-reanalysis-removed.md](0001GG-SharedBooleanVirtualStubs-current-no-owner-reanalysis-removed.md). The archived block is non-authoritative and must not be executed.

Expected post-validation state for UID `0001GG`:

- Target page remains `CANONICAL_OWNER:NONE`.
- Target page remains `RECONSTRUCTABLE:TRUE`.
- Target page keeps blank `EMITTER_UIDS`.
- Target page keeps blank `CPP`.
- `auto-generated/-ag-memory-coverage.md` still reports no owner and no emitters for the row.
- `by-memory/-coverage-report.md` reports range `0x0055c1b0-0x0055c1c3`, score `86%`, and no source owner claim beyond descriptive `SharedBooleanVirtualStubs`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001GG-SharedBooleanVirtualStubs-current-no-owner-reanalysis.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001GG"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001GG-SharedBooleanVirtualStubs-current-no-owner-reanalysis-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001GG-SharedBooleanVirtualStubs-current-no-owner-reanalysis.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001GG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
