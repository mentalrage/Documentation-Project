** TARGET-REPORT-UID:00005X **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00005X GroupListPane Source-Quality Reanalysis

Report-only B001 pass for [UID:00005X] `by-class/GroupListPane.md`.

Required output path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\00005X-GroupListPane-class-source-quality.md`

No `by-*` documentation file was edited for this pass. No coverage report was edited; `by-memory/-coverage-report.md` was not edited.

## Target And Current State

Target page:

- [UID:00005X][GroupListPane](../../../by-class/GroupListPane.md)
- Current metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000JS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JS`, formal C++ blank.
- Current source placement: [UID:0000JS][Group](../../../by-file/Group.md), generated destination `auto-generated/NexusTK/social/Group.cpp`.
- Current class coverage row says `75%`, which is stale against the target's `85/86` metadata and against the newer support pages.

Support pages reviewed:

- [UID:0000JS][Group](../../../by-file/Group.md)
- [UID:00005Y][GroupPane](../../../by-class/GroupPane.md)
- [UID:00005Z][GroupPane2](../../../by-class/GroupPane2.md)
- [UID:0001H8][0x0056baa0-0x0056bafd.GroupListPaneRawConstructor](../../../by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md)
- [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](../../../by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md)
- [UID:0002NI][0x00624210-0x006242c4.GroupListPaneVtableData](../../../by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md)
- [UID:0001XP][GroupPaneFamilyVtables](../../../by-type/by-vtable/GroupPaneFamilyVtables.md)
- [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](../../../by-memory/0x0056c4c0-0x0056e939.GroupPanes.md)
- [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](../../../by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md)
- [UID:0000DK][SpelledPane](../../../by-class/SpelledPane.md)
- [UID:00023W][0x0056c4a0-0x0056c4b5.LegendPaneFalseVirtualStubs](../../../by-memory/0x0056c4a0-0x0056c4b5.LegendPaneFalseVirtualStubs.md)
- [UID:0000QX][g_pFontImageLib](../../../by-global/g_pFontImageLib.md)
- [UID:0000JH][FontImageLib](../../../by-file/FontImageLib.md)
- [UID:0001P2][0x0067ab24-0x0067ab28.g_pFontImageLib](../../../by-memory/0x0067ab24-0x0067ab28.g_pFontImageLib.md)
- [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](../../../by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md)
- [UID:0000SW][g_useEpfAssets](../../../by-global/g_useEpfAssets.md)
- [UID:0002ZY][0x0058dce0-0x0058e132.TextEditPaneConstructor](../../../by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md)
- [UID:0001JM][0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane](../../../by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md)
- [UID:0000EO][TextEditPane](../../../by-class/TextEditPane.md)
- [UID:0000ON][TextEditPane](../../../by-file/TextEditPane.md)
- [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](../../../by-memory/0x005446b0-0x005446d4.PaneSetMode.md)
- [UID:0000E3][StaticTextControlPane](../../../by-class/StaticTextControlPane.md)
- [UID:00011I][0x00499030-0x004991ec.StaticTextControlPaneConstructor](../../../by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md)
- Prior B001 report [0001HC GroupPanes source-quality](executed/0001HC-GroupPanes-source-quality.md)

Current live IDA/MCP evidence was attempted but not available in this runtime. The HTTP MCP endpoint at `http://127.0.0.1:13337/mcp` failed with "Unable to connect to the remote server". This report therefore treats the linked pages' saved live-IDA evidence as the authoritative binary evidence and explicitly marks conclusions that are inferences from those pages.

## Exact Evidence Checked

The raw constructor page [UID:0001H8] records the exact constructor body as `0x0056baa0-0x0056bafd`, not the older padded `0x0056baa0-0x0056bb00` range. Saved live IDA evidence says:

- `lookup_funcs` reports no IDA auto-function at `0x0056baa0` or `0x0056bafd`.
- The predecessor `0x0056ba99-0x0056baa0` and successor `0x0056bafd-0x0056bb00` bytes are `0xcc` padding.
- A unique constructor-shaped byte signature starts with `push ebp; mov ebp, esp; ...` and ends with `5e 8b e5 5d c3` at `0x0056bafc`, followed by three `0xcc` bytes.
- `xrefs_to 0x0056baa0` has no direct code/data refs.
- `xrefs_to` the three `GroupListPane` vtable bases returns stores from the raw constructor and from inline child construction in `GroupPane` and `GroupPane2`.

The constructor byte sequence recorded in [UID:0001H8] is:

```text
55 8b ec 51 56 8b f1 8b 0d 24 ab 67 00 6a 00 6a 01
89 75 fc e8 f7 a5 f4 ff 50 6a 06 6a 01 6a 00 6a 00
68 80 00 00 00 6a 54 68 91 00 00 00 6a 54 68 91 00
00 00 8b ce e8 04 22 02 00 c7 06 14 42 62 00 8b c6
c7 86 a0 00 00 00 8c 42 62 00 c7 86 a4 00 00 00 bc
42 62 00 5e 8b e5 5d c3 cc cc cc
```

The same page records these constructor and inline-constructor stores:

| Evidence | Raw constructor | `GroupPane` inline | `GroupPane2` inline | Meaning |
| --- | ---: | ---: | ---: | --- |
| `g_pFontImageLib` / `dword_67AB24` read | `0x0056baa7` | `0x0056c52c` | `0x0056c7dc` | Loads the global font-image singleton before the mode helper call. |
| `IsLegacyAssetMode` / `sub_4B60B0` call | `0x0056bab4` | `0x0056c536` | `0x0056c7e6` | Returns the legacy/non-EPF mode flag. |
| `TextEditPane::TextEditPane` / `sub_58DCE0` call | `0x0056bad7` | `0x0056c559` | `0x0056c809` | Constructs the `TextEditPane` base/subobject with fixed group-list dimensions and flags. |
| primary vptr `0x00624214` | `0x0056badc` | `0x0056c55e` | `0x0056c80e` | Primary `GroupListPane` vtable view. |
| secondary vptr `0x0062428c` at `+0xa0` | `0x0056bae4` | `0x0056c564` | `0x0056c814` | Secondary adjusted `GroupListPane` vtable view. |
| tertiary vptr `0x006242bc` at `+0xa4` | `0x0056baee` | `0x0056c56e` | `0x0056c81e` | Tertiary adjusted `GroupListPane` vtable view. |

`GroupPane` and `GroupPane2` inline setup is saved in [UID:0001H8] and [UID:0001HC]:

- Both allocate `0x174` / 372 bytes for the child.
- Both use the same setup sequence as the standalone constructor island.
- Both install the same three `GroupListPane` vtable views.
- Both store the child at parent offset `+0xf8`.
- Both enable the child through [UID:0002V7] `Pane::SetMode(1)`.
- Both position/sync the child through `sub_58EA80` / a TextEditPane editable-active state helper.

The vtable-data page [UID:0002NI] records exact `.rdata` boundaries:

- `0x00624210-0x00624288`: primary `GroupListPane` view.
- `0x00624288-0x006242b8`: secondary adjusted view.
- `0x006242b8-0x006242c4`: tertiary adjusted view.
- `0x006242c4` starts the neighboring `SpelledPane` RTTI locator, so it is not part of `GroupListPane`.

Important vtable slots from [UID:0002NI]:

| Address | Value | Interpretation |
| ---: | ---: | --- |
| `0x00624210` | `??_R4GroupListPane@@6B@` | Primary RTTI locator. |
| `0x00624214` | `0x0048c4d0` | Primary inherited/shared vtable base slot. |
| `0x00624274` | `0x0056bb10` | Group-list-specific one-argument false virtual stub. |
| `0x00624288` | `??_R4GroupListPane@@6B@_0` | Secondary RTTI locator. |
| `0x0062428c` | `0x0048c2e9` | Secondary inherited/shared vtable base slot. |
| `0x00624294` | `0x0056bb00` | Group-list-specific one-argument false virtual stub. |
| `0x006242b8` | `??_R4GroupListPane@@6B@_1` | Tertiary RTTI locator. |
| `0x006242bc` | `0x0048c2f4` | Tertiary inherited/shared vtable base slot. |
| `0x006242c0` | `0x00544e90` | Tertiary tail slot, inherited/shared. |

The virtual-stub page [UID:0001H9] records:

- `0x0056bb00-0x0056bb05`: `xor al, al; retn 4`.
- `0x0056bb05-0x0056bb10`: eleven `0xcc` bytes.
- `0x0056bb10-0x0056bb15`: `xor al, al; retn 4`.
- `0x0056bb15-0x0056bb20`: trailing `0xcc` padding before the `SpelledPane` function.
- No callees and no direct code callers.
- `0x0056bb00` has only the vtable data ref at `0x00624294`.
- `0x0056bb10` has only the vtable data ref at `0x00624274`.

The source placement pages checked:

- [UID:0000JS] `Group` already lists `GroupListPane` as a feature-local class under `social/Group.cpp`.
- [UID:0001HC] keeps `GroupListPane` raw constructor/stubs separate from the broad `GroupPane`/`GroupPane2`/`NewGroupPane` aggregate.
- Prior B001 report `0001HC-GroupPanes-source-quality.md` keeps `GroupPane`, `GroupPane2`, `NewGroupPane`, `GroupListPane`, and `ScrollNewGroupPane` in the same feature root, with a possible future narrower `GroupPane.cpp` but no binary proof for an original separate file.

Helper/global pages checked:

- [UID:0000QX] `g_pFontImageLib` resolves `dword_67AB24` as a process-wide `FontImageLib *` singleton with 52 refs and owner writes/clears from `FontImageLib`.
- [UID:0003XA] `IsLegacyAssetMode` resolves `sub_4B60B0` as a no-argument mode query that returns `byte_66DA97 != 1`.
- [UID:0000SW] `g_useEpfAssets` resolves `byte_66DA97` as the current EPF/high-layout mode selector; `IsLegacyAssetMode` returns the inverse/non-EPF condition.
- [UID:0002ZY] `TextEditPane::TextEditPane` resolves `sub_58DCE0` as the `TextEditPane` constructor, with 26 direct callers including the three `GroupListPane` construction forms.
- [UID:0002V7] `Pane::SetMode` resolves `sub_5446B0` as `void Pane::SetMode(unsigned char mode)`, writing `Pane +0xb5` and invalidating the pane bounds on change.
- [UID:00011I] `StaticTextControlPane::StaticTextControlPane` provides corroborating evidence for `sub_58EA80(child, 0, 0)` as a TextEditPane editable/active mode setter used to disable editing/activation for an embedded text pane.

## Heuristic / Inference Reanalysis And Validation

### Source-Facing Class Role

Best inference: `GroupListPane` is a thin, source-authored `TextEditPane`-derived group-list child used by older `GroupPane` and `GroupPane2` shells.

Evidence:

- Object allocation size is `0x174` / 372 in both parent inline constructors. This matches the `TextEditPane`-sized child pattern documented in `StaticTextControlPane`, not a small bespoke list node.
- The standalone constructor and inline setup call `TextEditPane::TextEditPane`, then overwrite the primary and adjusted vptrs with `GroupListPane` vtables at `+0`, `+0xa0`, and `+0xa4`.
- The raw constructor contains no class-specific data-field writes after base construction except vptr installation.
- The only class-specific executable bodies currently proved after construction are two trivial false virtual stubs.

Rejected alternatives:

- Standalone generated dead constructor only: rejected as the sole model because `GroupPane` and `GroupPane2` inline the same vtable installation and keep a real child pointer at `+0xf8`; the class exists even if the standalone constructor has no direct xref.
- `GroupPane`/`GroupPane2` embedded anonymous text pane only: rejected because the RTTI/vtable data is named `GroupListPane`, and both parent constructors install `GroupListPane` vtables rather than leaving the base `TextEditPane` vtables in place.
- `SpelledPane` ownership: rejected because `0x0056bb20` has its own `SpelledPane` construction, vtable/RRTI boundary starts at `0x006242c4`, and non-group callers are documented.
- `ScrollNewGroupPane` ownership: rejected because `ScrollNewGroupPane` belongs to the newer `NewGroupPane` path and has separate ranges under `0x00560900-0x00561db0`; `GroupListPane` is the older text-list child in `GroupPane`/`GroupPane2`.

### Source/Header Placement

Best current placement: keep direct owner/emitter [UID:0000JS] `Group`, generated as `NexusTK/social/Group.cpp`.

Reasoning:

- The strongest positive evidence is feature ownership: both direct construction consumers are `GroupPane` and `GroupPane2`, and the class vtable family is documented under `GroupPaneFamilyVtables`.
- The class is not a reusable `TextEditPane` implementation detail; it only specializes the group-list child vtable shape.
- A future physical split such as `NexusTK/social/GroupPane.cpp` remains plausible, but no current binary evidence proves an original separate source file. The documentation should therefore keep stable owner/emitter [UID:0000JS] and mention the possible source-tree refinement only as a future organization option.

Rejected placements:

- [UID:0000ON] `TextEditPane`: owns the base constructor and text-edit helpers, not the `GroupListPane` RTTI/vtables or parent child ownership.
- [UID:0000JH] `FontImageLib`: owns `g_pFontImageLib`, but the constructor's load of `dword_67AB24` is a consumer artifact and not a class/file ownership signal.
- [UID:0000SW] `g_useEpfAssets` / [UID:0000O5] `StartupWindow`: own the mode byte and mode helper, not this group pane child.
- [UID:0000DK] `SpelledPane`: separate successor class, separate vtable boundary, and documented non-group callers.
- `MainUiGraph` or broad UI core: the class has no evidence of broad creation outside group pane constructors.

### Constructor Reachability And Modeling

Best source-facing constructor name/signature: `GroupListPane::GroupListPane()` as a no-argument constructor in source, with the fixed `TextEditPane` base setup encoded in the constructor body.

Confidence: high for no external constructor parameters; medium-high for exact declaration because the standalone emitted body has no direct xref and the same construction is inlined inside the parent constructors.

Evidence:

- The raw island uses only `this` in `ecx`, constants, `g_pFontImageLib`, and `IsLegacyAssetMode`.
- No caller provides additional constructor arguments.
- Parent constructors inline the same fixed setup instead of calling the standalone constructor.
- MSVC can emit a standalone constructor body and also inline the same body into other constructors.

Do not model the no-xref raw constructor as arbitrary data. It has exact prologue/body/epilogue, exact vptr stores, exact padding, and exact inline parity. But also do not overstate live call reachability: no direct route to `0x0056baa0` has been proved.

### Helper Names And Field/Global Meanings

| Binary/generated name | Best source-facing name/role | Confidence | Evidence and closure |
| --- | --- | --- | --- |
| `dword_67AB24` | `g_pFontImageLib` / `FontImageLib *` singleton | High | [UID:0000QX] documents backing storage [UID:0001P2], 52 refs, FontImageLib constructor write and destructor clears. In GroupListPane construction the value is loaded into `ecx` before the mode helper, but the accepted helper body does not dereference it. |
| `sub_4B60B0` | `IsLegacyAssetMode()` / `IsLegacyUiMode()` descriptive query | High for behavior, medium for exact spelling | [UID:0003XA] body is `xor eax,eax; cmp byte_66DA97,1; setnz al; retn`. It returns true for non-EPF/legacy mode and is owned by [UID:0000SW] `g_useEpfAssets`, not FontImageLib. |
| Stale "resource/context pointer returned by `sub_4B60B0`" | Reject; replace with "legacy-mode flag returned by `IsLegacyAssetMode`" | High | The current GroupListPane/raw-constructor docs are stale here. The pushes before the helper are later `TextEditPane` constructor args, not `sub_4B60B0` args. The helper has no stack cleanup and no object-state read. |
| `sub_58DCE0` | `TextEditPane::TextEditPane(...)` | High for class/role, medium for exact full parameter list | [UID:0002ZY] resolves the exact constructor, owner [UID:0000EO], and lists direct callers including `0x0056bad7`, `0x0056c559`, and `0x0056c809`. |
| Fixed constructor dimensions | `145 x 84` text/list viewport setup | High | Raw and inline paths pass `0x91` / 145 and `0x54` / 84 pairs. These should be documented as group-list fixed dimensions, not field names. |
| `0x80`, `0`, `0`, `1`, `6`, legacy-mode flag, `1`, `0` TextEditPane args | TextEditPane style/format/scroll/edit/display-mode constants | Medium | `TextEditPane::TextEditPane` parameter names remain unresolved. The old "resource pointer" interpretation is wrong; the mode flag is one parameter among the fixed setup pattern. |
| `sub_5446B0` | `Pane::SetMode(unsigned char mode)` | High | [UID:0002V7] has formal C++ and resolves `+0xb5` mode byte plus invalidation side effect. Inline parent constructors use this to set the child mode to `1`. |
| `sub_58EA80` | `TextEditPane::SetEditableOrActiveMode(bool editable, bool active)` / text-pane editability/activation setter | Medium | [UID:00011I] calls `0x0058ea80(child, 0, 0)` and documents it as disabling editing/activation. GroupPane/GroupPane2 inline setup uses it after enabling/positioning the child. Exact original method name is not safe without a TextEditPane helper pass. |
| `GroupPane +0xf8` / `GroupPane2 +0xf8` | `GroupListPane *m_groupListPane` | High | [UID:0001HC] field table resolves parent `+0xf8` as the allocated `0x174` child with `GroupListPane` vtables. |
| `GroupListPane +0x00` | primary vptr | High | Constructor stores `0x00624214`; vtable data starts at `0x00624210`. |
| `GroupListPane +0xa0` | secondary adjusted vptr | High | Constructor stores `0x0062428c`; vtable data secondary view starts at `0x00624288`. |
| `GroupListPane +0xa4` | tertiary adjusted vptr | High | Constructor stores `0x006242bc`; vtable data tertiary view starts at `0x006242b8`. |
| Additional `GroupListPane` fields beyond inherited `TextEditPane` | No proved class-local data fields | High | Constructor writes no class-local fields after `TextEditPane` construction except vptrs. No support page shows a `GroupListPane`-specific field access outside inherited layout. |

### Virtual Stub Names

Best inference: the two five-byte stubs are one-argument `bool` virtual overrides/default handlers that intentionally return false. They are likely action/query gates inherited from the pane/text-edit interface.

Recommended source-facing documentation names:

- `GroupListPane::CanHandlePrimaryAction(int action)` or `GroupListPane::OnPrimaryAction(int action)` for the primary slot at `0x00624274 -> 0x0056bb10`.
- `GroupListPane::CanHandleSecondaryAction(int action)` or `GroupListPane::OnSecondaryAction(int action)` for the secondary slot at `0x00624294 -> 0x0056bb00`.

Do not write those as final names yet. The evidence only proves:

- Each body returns `false` in `AL`.
- Each body consumes one 4-byte argument via `retn 4`.
- Both are vtable-only, with no direct callers/callees.
- The slot owner is `GroupListPane`.

Why exact names remain unsafe:

- The current pass did not have live IDA available to compare these slots against fully named `TextEditPane`, `StaticTextControlPane`, `ClanInfoListPane`, `SpelledPane`, and `GroupPane` sibling vtable slots.
- The primary and secondary vtable interfaces may use different source names even though both bodies are the same false-return idiom.
- The decompiler's `char __stdcall(...)` shape is an ABI artifact from an adjusted vtable slot, not sufficient to infer a public method name.

### Inheritance/Base Initializer

Best inference: source declaration is most likely a `TextEditPane`-derived class with no data members beyond inherited subobjects:

```cpp
// Do not emit yet; source-quality sketch only.
class GroupListPane : public TextEditPane
{
public:
    GroupListPane();

    // Two false-return virtual overrides exist, names unresolved.
};
```

Likely constructor source shape, also not ready to emit:

```cpp
// Do not emit yet; parameter names and exact TextEditPane signature remain unresolved.
GroupListPane::GroupListPane()
    : TextEditPane(145, 84, 145, 84, 0x80, 0, 0, 1, 6,
                   IsLegacyAssetMode(), 1, 0)
{
}
```

This sketch captures the binary shape but must not be placed in formal C++ yet because:

- `TextEditPane::TextEditPane` is documented as not final-source ready for parameter names/signature.
- The constructor call has unresolved semantic names for the `0x80`, `6`, and boolean/style parameters.
- The vtable stub original method names are still unresolved.
- The class declaration would force inheritance/interface decisions that should come from a TextEditPane/vtable slot pass, not from this class page alone.

### Boundary And Split Decisions

Resolved:

- `0x0056baa0-0x0056bafd` is the exact raw constructor body. The `0x0056bafd-0x0056bb00` bytes are padding.
- `0x0056bb00-0x0056bb15` contains two exact `GroupListPane` false virtual stubs and internal padding.
- `0x0056bb15-0x0056bb20` is padding before the next function.
- `0x0056bb20-0x0056c3f1` is `SpelledPane`/text-edit construction and related methods, not clean `GroupListPane` ownership.
- `0x00624210-0x006242c4` is the exact `GroupListPane` vtable-data child. `0x006242c4` starts `SpelledPane` RTTI.
- `0x0056c4a0-0x0056c4b5` is `LegendPane` false virtual stub boundary context, not `GroupListPane` or `GroupPane` source.
- `0x0056c4c0-0x0056e939` remains the broader `GroupPanes` aggregate and should not absorb the `GroupListPane` raw constructor/stub pages.

### Caller/Reachability Closure

The no-direct-xref fact is real and should remain documented:

- No direct caller to `0x0056baa0` is recorded in saved live evidence.
- No direct callers to `0x0056bb00` or `0x0056bb10` exist; they are vtable-only.

But the no-direct-xref fact is not enough to demote the class below reconstructable:

- Parent constructors duplicate the constructor body inline, proving source-level construction.
- The vtable data is explicit and named.
- The parent fields store a `GroupListPane` child pointer.
- The class object size and base-constructor call are consistent across standalone and inline paths.

The best model is therefore "source-authored class with raw/manual standalone constructor emission and inline parent-construction parity", not "dead orphan function" and not "only a parent-local anonymous text pane".

### Open Questions Closure

No open question should be left as generic future work. Current closure:

- Exact original source filename: best supported current owner is `Group.cpp`; a narrower `GroupPane.cpp` is plausible but unproved.
- Exact constructor source signature: `GroupListPane::GroupListPane()` is high probability, but formal C++ should wait because the base constructor signature is not source-ready.
- Exact `TextEditPane` parameter names: unsafe from this target; current report records constants and roles and rejects the stale resource-pointer interpretation.
- Exact `sub_58EA80` name: not source-safe; best role is TextEditPane editability/activation setter based on `StaticTextControlPane` and group inline use.
- Exact false-stub method names: not source-safe; best role is one-argument false action/query gates.
- Whether `g_pFontImageLib` is semantically consumed by `IsLegacyAssetMode`: no. The binary loads `g_pFontImageLib` into `ecx` before calling the helper, but the accepted helper body reads only `byte_66DA97`. Preserve the load as call-site ABI/codegen evidence, not as helper semantics.
- Whether `GroupListPane` has additional fields: no current evidence. Treat it as a thin `TextEditPane` specialization until a future xref pass proves a class-local field access.

## Source-Quality Recommendations

### Metadata

Recommended target metadata:

- `COMPLETION:87`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000JS` unchanged
- `RECONSTRUCTABLE:TRUE` unchanged
- `EMITTER_UIDS:0000JS` unchanged
- Formal C++ remains blank

Why not lower:

- The current page already clears `85/85`.
- This pass strengthens, rather than weakens, class identity, source placement, boundary, and field/layout evidence.
- The stale `sub_4B60B0` interpretation is correctable from accepted support pages and does not invalidate the constructor shape.

Why not raise to 90+:

- Current live IDA was unavailable in this runtime.
- The standalone constructor remains a no-direct-xref raw/manual boundary.
- `TextEditPane::TextEditPane` full source signature is not final.
- `sub_58EA80` exact source method name is unresolved.
- The two false virtual stubs have role-level but not original source names.
- No class-level C++ should be emitted until the declaration/vtable names are safer.

### Title/Body Naming

Keep the title `GroupListPane`.

Use these source-facing names in target/support docs:

- `GroupListPane`
- `GroupListPane::GroupListPane()` for the raw constructor role, with no formal C++ emission yet.
- `TextEditPane::TextEditPane(...)` for `sub_58DCE0`.
- `Pane::SetMode(1)` for `sub_5446B0` child enabling.
- `g_pFontImageLib` for `dword_67AB24`.
- `IsLegacyAssetMode()` for `sub_4B60B0`, with an alias note `IsLegacyUiMode()` remains plausible until final naming.
- `TextEditPane::SetEditableOrActiveMode(false, false)` / "TextEditPane editability/activation setter" for `sub_58EA80`, explicitly role-based and not final spelling.
- `GroupListPane` false virtual stubs / one-argument action/query gates for `0x0056bb00` and `0x0056bb10`.

Remove or correct this stale wording wherever touched:

- "sub_4B60B0 produces the resource/context pointer consumed by the text/list initializer."

Replace with:

- "`g_pFontImageLib` is loaded before the helper call, but accepted helper evidence resolves `sub_4B60B0` as `IsLegacyAssetMode()`, a `g_useEpfAssets`/`byte_66DA97` query returning the legacy/non-EPF mode flag. The helper result is passed into `TextEditPane::TextEditPane` as a display/layout mode argument."

### First-Draft C++ Recommendation

Do not emit first-draft C++ in [UID:00005X] now.

Target-specific no-code proof:

- `by-class/GroupListPane.md` is a class overview page, not the exact method-body page.
- A class declaration would require exact base/interface and virtual method names; those are not currently source-quality.
- The only likely C++ body for this class is the constructor, but that exact method is covered by [UID:0001H8] and has no direct xref while the same logic is inlined in two parent constructors.
- Emitting the constructor now would force unresolved `TextEditPane::TextEditPane` parameter names and would likely encode misleading numeric constants as if they were final API names.
- The two stub bodies are exact but their method names are not.
- The generated `auto-generated/NexusTK/social/Group.cpp` currently has emitter markers with no `GroupListPane` code. Keeping the class page non-emitting avoids speculative declarations while preserving reconstructable metadata.

Future first-draft C++ may become safe after a TextEditPane/vtable-slot naming pass. At that point, likely code belongs in exact method children, not as a class-page overview blob.

## Rejected Alternatives

`sub_4B60B0` as FontImageLib/resource-context helper:

- Rejected. The helper body reads only `byte_66DA97` and returns `byte_66DA97 != 1`. `g_pFontImageLib` is loaded into `ecx` before the call in GroupListPane construction, but current accepted helper evidence says it is not dereferenced. The stale wording should be removed from GroupListPane pages.

`GroupListPane` as pure generated compiler artifact:

- Rejected. RTTI/vtable data, vtable stores, parent fields, and inline construction parity prove a real source-level class.

`GroupListPane` constructor as live-call-required only:

- Rejected. Lack of a direct call means reachability is unresolved for the standalone body, but parent inline construction is enough to model source-authored constructor logic and class identity.

Merge into `GroupPanes` aggregate:

- Rejected. [UID:0001HC] is a feature aggregate and already says not to merge the exact raw constructor/stub pages. The target class page should point to the exact children.

Merge with `SpelledPane`:

- Rejected. `SpelledPane` starts at `0x0056bb20` and its RTTI starts at `0x006242c4`; it has non-group callers and separate class/file ownership.

Move owner to `TextEditPane`:

- Rejected. `TextEditPane` owns base construction and common helpers, but `GroupListPane` RTTI/vtables and parent consumers are group-specific.

Move owner to `FontImageLib` or `g_useEpfAssets`:

- Rejected. Those pages own globals/helpers consumed during construction, not the group-list child class.

## Target/Support Implementation Checklist

If accepted, later implementation should edit only the following by-* support docs and then validate each touched file with `--apply --queue-timeout 240`.

Target page [UID:00005X] `by-class/GroupListPane.md`:

- Update metadata to `COMPLETION:87`, `CONFIDENCE:89`; keep owner/emitter [UID:0000JS], `RECONSTRUCTABLE:TRUE`, formal C++ blank.
- Add or rewrite status to say confidence is very strong for class identity/layout/source placement, but still below final C++ because of constructor no-xref/manual boundary and unresolved TextEditPane/vtable names.
- Replace stale `sub_4B60B0` resource-context wording with `IsLegacyAssetMode()` / `g_useEpfAssets` semantics.
- Add a small source-quality table for `g_pFontImageLib`, `IsLegacyAssetMode`, `TextEditPane::TextEditPane`, `Pane::SetMode`, and `sub_58EA80` role.
- Add layout statement: object size `0x174`, primary/secondary/tertiary vptrs at `+0/+0xa0/+0xa4`, no proved class-local fields beyond inherited `TextEditPane`.
- Add parent ownership statement: `GroupPane` and `GroupPane2` store `GroupListPane *m_groupListPane` at `+0xf8`.
- Add no-code proof from this report.
- Add change note for B001 source-quality reanalysis.

Support [UID:0001H8] `by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md`:

- Correct behavior/touched-state wording for `dword_67AB24` and `sub_4B60B0`.
- Document the argument-building nuance: pushes before `IsLegacyAssetMode()` are pending `TextEditPane::TextEditPane` args; the helper itself has no stack args and no stack cleanup.
- Use `TextEditPane::TextEditPane(...)`, `IsLegacyAssetMode()`, and `Pane::SetMode(1)` names in source-quality sections.
- Preserve exact raw bytes, padding, no-xref status, inline parity, and vtable store addresses.
- Keep formal C++ blank unless supervisor separately accepts exact method-child C++ after TextEditPane names are ready. No score change required, but `87/90` would be defensible if supervisor wants to reflect the corrected helper semantics.

Support [UID:0001H9] `by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md`:

- Add role-level names: one-argument false-return action/query gate virtuals.
- State exact source names remain unsafe pending vtable-slot comparison.
- Preserve exact bytes, padding, vtable-only refs, and no direct caller/callee evidence.
- No formal C++ yet unless the exact virtual names are resolved.

Support [UID:0002NI] `by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md`:

- Add cross-note that the class source-quality pass resolves the constructor helper semantics and no-extra-field model.
- Keep parent [UID:0001XP] and score unchanged unless broader vtable-family pass changes slot names.

Support [UID:0001XP] `by-type/by-vtable/GroupPaneFamilyVtables.md`:

- Add a brief note under `GroupListPane` slots that `0x0056bb10` and `0x0056bb00` are one-argument false action/query gates with exact original names unresolved.

Support [UID:0000JS] `by-file/Group.md`:

- Refresh `GroupListPane` source-quality caveat: constructor helper names are now corrected; remaining cap is exact TextEditPane signature, `sub_58EA80`, virtual names, and no direct standalone constructor xref.
- Keep source root `NexusTK/social/Group.cpp`; optionally note a future `GroupPane.cpp` split is source-tree organization only, not binary-proved.

Support [UID:00005Y] `by-class/GroupPane.md` and [UID:00005Z] `by-class/GroupPane2.md`:

- Update inline child setup wording to `GroupListPane *m_groupListPane` at `+0xf8`, `TextEditPane::TextEditPane`, `IsLegacyAssetMode`, `Pane::SetMode(1)`, and `TextEditPane` editable/activation setter.
- Avoid stale resource/context-pointer language.

Support [UID:0001HC] `by-memory/0x0056c4c0-0x0056e939.GroupPanes.md`:

- If touched for cross-reference consistency, add the same corrected helper semantics in the `GroupPane`/`GroupPane2 +0xf8` row or nearby evidence bullets.
- Preserve the already-correct split boundary around `GroupListPane`, `SpelledPane`, and `LegendPane`.

Optional support backrefs only if supervisor wants cross-link completeness:

- [UID:0000QX] `by-global/g_pFontImageLib.md`: add `GroupListPane` as a consumer that loads the singleton before TextEditPane setup, with no claim that `IsLegacyAssetMode` dereferences it.
- [UID:0003XA] `by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md`: add `GroupListPane` constructor and parent inline constructors as representative callers.
- [UID:0002ZY] `by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md`: current caller list already includes the three GroupListPane construction forms; no required change.
- [UID:0002V7] `PaneSetMode`: no required change.
- `SpelledPane` and `LegendPane` pages: no content change required; cite only as boundary exclusions.

Generated/source actions:

- Do not add `GroupListPane` formal C++ in the class page during this callback.
- Do not edit `auto-generated/NexusTK/social/Group.cpp` directly; let validator/autogen update if metadata/content requires it.

Validator commands for later implementation callback:

> Executable block R001 was removed from this report and preserved verbatim in [00005X-GroupListPane-class-source-quality-removed.md](00005X-GroupListPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run only the commands corresponding to files actually edited, plus the target.

## Exact Supervisor-Owned Coverage Row

Do not edit coverage during this report-only pass. If the report is accepted, the supervisor-owned `by-class/-coverage-report.md` replacement row should be:

```text
- [UID:00005X][GroupListPane](by-class/GroupListPane.md) : reconstructable : 87% : very strong : B001 source-quality reanalysis keeps the class under [UID:0000JS][Group](by-file/Group.md) and resolves it as a thin `TextEditPane`-derived group-list child (`0x174` bytes) constructed by raw no-xref island [UID:0001H8] and inlined in `GroupPane`/`GroupPane2`; vtable data [UID:0002NI] confirms three views at `+0/+0xa0/+0xa4`, two one-argument false virtual gates [UID:0001H9], `GroupPane`/`GroupPane2 +0xf8` child ownership, `g_pFontImageLib` load / `IsLegacyAssetMode` display-mode helper / `TextEditPane::TextEditPane` setup semantics, SpelledPane and LegendPane boundary exclusions, and no class-level C++ readiness because constructor reachability, exact `TextEditPane` signature, `sub_58EA80` source name, and virtual-slot names remain unresolved.
```

`by-memory/-coverage-report.md` has no required row edit for this class-only assignment and was not edited.

## Scoped Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R002 was removed from this report and preserved verbatim in [00005X-GroupListPane-class-source-quality-removed.md](00005X-GroupListPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`
- `mode: file`
- `apply: False`
- `scanned markdown files: 1`
- Target result: `ok           00005X by-class/GroupListPane.md UID header exists`
- Dry-run note: `stats_incremental_skip 00005X project-level/-auto-completion-stats.md dry run; pass --apply to update generated stats rows`
- Generated registry dry run rebuilt in memory and reported many unrelated `autogen_emitter_has_no_code` / `autogen_cpp_noop` lines.
- Final line: `dry run only; pass --apply to write changes`

No validator command wrote files during this report-only pass.

## Final Recommendation

Raise [UID:00005X] to `87/89`, keep owner/emitter [UID:0000JS], keep formal C++ blank, and incorporate the corrected helper/global semantics into the target and support docs.

The most important correction is to replace the stale "resource/context pointer from `sub_4B60B0`" model with the accepted `IsLegacyAssetMode()` / `g_useEpfAssets` mode-query model. With that correction, the class shape is stronger than the current 85/86 wording: it is a real `TextEditPane`-derived group-list child with exact vtable data, exact raw constructor bytes, exact parent inline parity, and exact parent child-field ownership. It is still not first-draft-C++ ready because the source-facing `TextEditPane` constructor signature, `sub_58EA80` name, and false virtual slot names remain unresolved at source quality.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00005X-GroupListPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"00005X"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00005X-GroupListPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00005X-GroupListPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00005X"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
