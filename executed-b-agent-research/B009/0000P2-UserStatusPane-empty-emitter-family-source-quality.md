** TARGET-REPORT-UID:0000P2 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# B009 Report: [UID:0000P2] UserStatusPane Empty-Emitter Family Source Quality

Report-only assignment for `by-file/UserStatusPane.md`.

Status: implementation callback applied; awaiting supervisor verification/execution.

## Scope

Primary target:

- [UID:0000P2] `by-file/UserStatusPane.md`

Current generated root:

- `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp`

Current generated output has 27 markers for this file family, 9 filled markers, and 18 empty markers. This report maps the 18 current empty generated markers to source-quality dispositions and proposes implementation edits. No by-* documentation was edited for this report-first pass.

## Required Metadata Recommendation

For the primary by-file target, keep the existing file ownership and promote only after the proposed support edits are applied and validated:

- `COMPLETION:90`
- `CONFIDENCE:87`
- `CANONICAL_OWNER:FILE`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000P2`
- `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"`

Rationale: file ownership is source-real and current generated output already proves a viable file root. The remaining risk is not file placement; it is exact source naming and broad method-body completeness for the large UserStatusPane/UserStatusPane2 aggregates. The report therefore recommends a modest score increase from `88/85` to `90/87`, not a high-confidence final-source score.

## Key Disposition

The current empty-emitter set should not be treated as 18 missing method bodies. It is a mixed family:

- Class shells should emit declaration/prototype scaffolds with `[[CHILDREN]]`.
- Broad aggregate by-memory ranges should emit marker-only no-standalone C++ blocks, because exact child pages or later split pages own the bodies.
- Small exact accessor/setter pages should receive first-draft source C++ now.
- Vtable-data and exact storage pages should emit covered-by marker comments.
- File-level globals should emit zero-initialized source globals.
- `UserStatusPaneSummaryFields` is not a standalone source type and should become non-reconstructable support layout documentation.
- The two resource-string pages are source-use evidence, not standalone source bodies. `SharedNpal5PaletteResourceString` already has accepted no-standalone string-literal precedent from B014; `UserStatusPaneResourceStrings` should get an explicit no-code proof rather than a fake comment emitter or fabricated data definition.

## MCP Provenance

MCP was available and used. Evidence was gathered through narrow schema-current calls.

- MCP `initialize`: succeeded, protocol `2025-06-18`, server `ida-pro-mcp 1.0.0`.
- MCP `tools/list`: succeeded.
- IDB session: `supervisor_resume_20260629`.
- IDB input path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- IDA process state: active, backend worker, PID/worker PID `17592`.
- Auto analysis: ready.
- Hex-Rays: ready.
- Strings cache: ready, size `2067`.
- Module: `NexusTK.exe`.
- Image base: `0x400000`.

MCP calls used for this report:

- `lookup_funcs` for exact and boundary status-pane addresses.
- `get_bytes` for singleton storage, padding, vtable/string boundary bytes, and resource string bytes.
- `xrefs_to` for singleton globals, vtable anchors, resource strings, and adjacent negative boundary evidence.
- `entity_query` for named vtable/string anchors in the `0x00630c2c-0x00630f8c` region.
- `decompile` for the exact accessor/setter island and constructor/global-store shape.

No fallback-only evidence path was used.

## MCP Evidence Summary

### Function And Range Shape

`lookup_funcs` confirms the current target family is a mixture of exact functions, broad aggregates, and non-function byte/data regions:

- `0x005b83b0` `sub_5B83B0`, size `0x176`, UserStatusPane constructor region.
- `0x005b85b0` `sub_5B85B0`, size `0x1c`, exact summary accessor.
- `0x005b86d0`, not a function, supports keeping the adjacent signed-byte getter caveat out of the accessor block.
- `0x005b86e0` `sub_5B86E0`, size `0x18`, exact status icon setter.
- `0x005b8700` `sub_5B8700`, size `0x2b1`, UserStatusPane event/router body.
- `0x005ba4a0` `sub_5BA4A0`, size `0x65e`, UserStatusPane payload body.
- `0x005baafe`, not a function, range-end padding for [UID:0001NM].
- `0x005bab00` `sub_5BAB00`, size `0xf7`, UserStatusPane2 constructor.
- `0x005bac80` `sub_5BAC80`, size `0x28a`, UserStatusPane2 cleanup/router-adjacent method.
- `0x005bc420` `sub_5BC420`, size `0x1ec`, UserStatusPane2 payload/tail body.
- `0x005bc60c`, not a function, range-end padding for [UID:0001NO].
- `0x005bc610` `sub_5BC610`, size `0x4f`, first function after [UID:0001NO], supporting the current `0x005bc60c` boundary.

This is negative evidence against pasting broad aggregate C++ into [UID:0001NM] or [UID:0001NO]. Those aggregates are containers and should not become monolithic bodies.

### Singleton Storage And Xrefs

`get_bytes` and `xrefs_to` confirm the singleton storage bytes are currently zero-initialized in the IDB, not `ff ff ff ff`:

- `0x0069ae0c`: bytes `00 00 00 00`, xref count `67`, active UserStatusPane pointer.
- `0x0069b4e4`: bytes `00 00 00 00`, xref count `6`, UserStatusPane2 pointer.
- `0x0069b4ec`: bytes `00 00 00 00`, xref count `9`, OldUserStatusPane pointer.

Representative xrefs:

- `0x0069ae0c`: constructor/lifecycle writes at `0x005b83fa`, `0x005b8401`, clear at `0x005b858e`, additional lifecycle references at `0x005bfc00` and `0x005bff85`.
- `0x0069b4e4`: references include `0x00504925`, constructor stores at `0x005bab4a` and `0x005bab51`, and lifecycle references `0x005bfbf0`, `0x005bfec5`.
- `0x0069b4ec`: references include `0x0050490b`, `0x00598dec`, `0x0059c997`, constructor stores at `0x005bda8a` and `0x005bda91`, and lifecycle references `0x005bfbe0`, `0x005bfe05`.

Implementation should historicalize the stale `ff ff ff ff` notes in [UID:0000SN], [UID:0000RV], [UID:0002WE], and [UID:0002WG] as superseded older evidence.

### Vtable And Resource Boundaries

`entity_query` on `0x00630c2c-0x00630f8c` confirms distinct vtable regions:

- `??_7UserStatusPane@@6B@` at `0x00630c2c`; related labels at `0x00630c78` and `0x00630ca8`.
- `??_7UserStatusPane2@@6B@` at `0x00630cb4`; related labels at `0x00630d00` and `0x00630d30`.
- MenuVariety vtables begin at `0x00630d3c`, negative evidence that [UID:0002Z0] must stop at `0x00630d3c`.
- `??_7OldUserStatusPane@@6B@` at `0x00630e58`; related labels at `0x00630ea4` and `0x00630ed4`.

`get_bytes` for `0x00630edc` decodes the source literals in [UID:0003JC]:

- `USERSTAT.EPF`
- `USERSTAT.EPD`
- `NATION.EPD`
- `TOTEM.EPD`
- `CLASS.EPD`
- `%3u`
- `BAR.EPD`
- `%04u/%04u`
- `%03u`

`xrefs_to` confirms:

- `0x00630edc` has a status-pane paint xref at `0x005b8cd0`.
- `0x00630f8c` has a MenuVariety successor xref at `0x005bc841`, negative boundary evidence that the status resource block stops before `0x00630f8c`.

`get_bytes` for `0x00610fd0` decodes `NPAL5.PAL`. `xrefs_to` gives four consumers:

- `0x0046169d` FrameChrome
- `0x00467a20` BackPane
- `0x005b9519` UserStatusPane paint
- `0x005be938` OldUserStatusPane paint

This supports [UID:00044W] as a shared source-use literal, not a UserStatusPane-owned standalone data body.

### Accessor/Setter Decompile Evidence

Hex-Rays decompile supports exact first-draft C++ for [UID:0001NN] and [UID:0002LP]:

- `0x005b85b0`: `wcscpy_s(Destination, SizeInWords, this + 126)`, source name inferred as `CopyNameLineA`.
- `0x005b8670`: `wcscpy_s(this + 190, 0x40u, Source)` then calls vtable slot `+0x20` with `this + 34`, source name inferred as `SetDisplayLineA`.
- `0x005b86a0`: `wcscpy_s(this + 254, 0x40u, Source)` then calls vtable slot `+0x20` with `this + 34`, source name inferred as `SetDisplayLineB`.
- `0x005b86e0`: writes `this[639] = a2` and calls vtable slot `+0x20` with `this + 68`, source name inferred as `SetStatusIconId`.

The callback helper name `InvalidateSummaryText()` is source-facing inference. It must be labeled as inferred in support prose.

### Constructor Evidence

Decompile evidence shows each class constructor installs its own vtables and stores into the corresponding singleton pointer:

- UserStatusPane constructor at `0x005b83b0` installs vtables `0x00630c2c`, `0x00630c78`, and `0x00630ca8`; stores `this` or zero into `0x0069ae0c`; loads `9X11FONT.BIN`; copies the display-name source string; initializes summary bytes/values including a status-field default around `+0x284 = 52`.
- UserStatusPane2 constructor at `0x005bab00` installs vtables `0x00630cb4`, `0x00630d00`, and `0x00630d30`; stores `this` or zero into `0x0069b4e4`; clears compact fields; loads `9X11FONT.BIN`.
- OldUserStatusPane constructor at `0x005bda40` installs vtables `0x00630e58`, `0x00630ea4`, and `0x00630ed4`; stores `this` or zero into `0x0069b4ec`; loads the font; copies the display name; initializes legacy fields.

OldUserStatusPane implementation is already covered by accepted B002 work for [UID:0001NR] and exact child pages. This report only recommends the current empty vtable-data marker for [UID:0002Z3].

## Prior Report Incorporation

### B004, CharacterSummaryRecord / [UID:0001NN] / [UID:0001WF]

B004 accepted that `CharacterSummaryRecord` is not a standalone generated pseudo-class. It is folded into the UserStatusPane source family. This report preserves that finding:

- [UID:0001NN] is a real exact accessor island and should receive first-draft C++.
- [UID:0001WF] is a descriptive layout slice, not a standalone source type. It should become non-reconstructable layout documentation rather than emit a fake struct body.
- Field and helper names such as `m_nameLine`, `m_secondaryLine`, `m_displayLineA`, `m_percentStatA`, `m_nationId`, `m_spiritId`, and `InvalidateSummaryText()` are inferred source-facing names and must stay marked as inferred.
- The adjacent `0x005b86d0` signed-byte getter remains a caveat outside the [UID:0001NN] accessor block.

### B002, OldUserStatusPane / [UID:0001NR]

B002 accepted the OldUserStatusPane pattern:

- Class declaration shell with `[[CHILDREN]]`.
- Aggregate [UID:0001NR] with `[[CHILDREN]]`.
- Exact child pages carry exact method bodies.

Current generated output already reflects this pattern. This report does not propose changes to [UID:0001NR] or its exact body child pages. It only proposes a covered-by marker for the currently empty OldUserStatusPane vtable data page [UID:0002Z3].

### B014, Shared Resource String Literals

B014 accepted that shared source string-literal pages can remain reconstructable source-use evidence while their formal C++ block stays empty. It specifically covered [UID:00044W] `SharedNpal5PaletteResourceString` as shared `NPAL5.PAL` evidence.

This report applies the same standard:

- Do not add a comment-only emitter to [UID:00044W].
- Do not fabricate standalone data definitions for [UID:0003JC].
- Source-use emission belongs inside consuming method/file bodies when those bodies are reconstructed.

### B003, MenuVariety Empty-Emitter Precedent

B003 established the useful empty-emitter repair pattern for neighboring UI file families:

- Class pages can emit declaration/prototype shells with `[[CHILDREN]]`.
- Global pages can emit zero-initialized source global definitions.
- Vtable-data and exact-storage pages can emit covered-by marker comments.
- Stale `ff ff ff ff` initializer notes should be historicalized when current MCP bytes prove zero storage.

This report follows that pattern for UserStatusPane.

## Current Empty Marker Inventory And Proposed Disposition

| UID | Path | Current generated state | Proposed disposition |
| --- | --- | --- | --- |
| 0002Z3 | `by-memory/0x00630e58-0x00630edc.OldUserStatusPaneVtableData.md` | Empty vtable-data marker | Add covered-by marker for [UID:00009U] OldUserStatusPane class declarations. |
| 0000FS | `by-class/UserStatusPane.md` | Empty class marker | Add formal class shell with prototypes, inferred layout fields, `extern` singleton, and `[[CHILDREN]]`. |
| 0001NM | `by-memory/0x005b83b0-0x005baafe.UserStatusPane.md` | Empty broad aggregate marker | Add marker-only no-standalone C++ block; exact child pages own bodies. |
| 0001NN | `by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md` | Empty exact accessor marker | Add first-draft source C++ for copies/getters/setters. |
| 0002LP | `by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md` | Empty exact setter marker | Add first-draft source C++ setter. |
| 0002YZ | `by-memory/0x00630c2c-0x00630cb4.UserStatusPaneVtableData.md` | Empty vtable-data marker | Add covered-by marker for [UID:0000FS]. |
| 0001WF | `by-type/by-struct/UserStatusPaneSummaryFields.md` | Empty type marker | Change to non-reconstructable layout support; no C++ block. |
| 0000FT | `by-class/UserStatusPane2.md` | Empty class marker | Add formal class shell with prototypes and `[[CHILDREN]]`. |
| 0001NO | `by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md` | Empty broad aggregate marker | Add marker-only no-standalone C++ block; exact split/body work is outside this report's implementation scope. |
| 0002Z0 | `by-memory/0x00630cb4-0x00630d3c.UserStatusPane2VtableData.md` | Empty vtable-data marker | Add covered-by marker for [UID:0000FT]. |
| 0000PS | `by-global/g_activeUserStatusPane.md` | Empty global marker | Add zero-initialized source global definition. |
| 0000RV | `by-global/g_pOldUserStatusPane.md` | Empty global marker | Add zero-initialized source global definition and historicalize stale `ff` initializer language. |
| 0002WG | `by-memory/0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md` | Empty exact-storage marker | Add covered-by marker for [UID:0000RV] and preserve current-zero evidence. |
| 0000SN | `by-global/g_pUserStatusPane2.md` | Empty global marker | Add zero-initialized source global definition and historicalize stale `ff` initializer language. |
| 0002WE | `by-memory/0x0069b4e4-0x0069b4e8.g_pUserStatusPane2.md` | Empty exact-storage marker | Add covered-by marker for [UID:0000SN] and replace stale `ff` initializer language with current-zero evidence. |
| 00044W | `by-memory/0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString.md` | Empty shared string marker | Already covered by B014 no-standalone literal precedent. Do not add marker or fake data C++. |
| 0003JC | `by-memory/0x00630edc-0x00630f8c.UserStatusPaneResourceStrings.md` | Empty status resource marker | Add/strengthen no-code proof in prose; keep formal C++ blank. |
| 0001PE | `by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md` | Empty exact-storage marker | Re-route direct owner/emitter to [UID:0000PS] and add covered-by marker. |

## Formal C++ Insertion Text

All C++ below is formal insertion text. Implementation should copy the whole applicable `RECONSTRUCTION_CPP CODE` block into the named target, replacing only the existing formal block value.

### [UID:0000FS] `by-class/UserStatusPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct RectBounds;
struct PaneEvent;

class UserStatusPane : public Pane
{
public:
    explicit UserStatusPane(const wchar_t *displayName);
    virtual ~UserStatusPane();

    errno_t CopyNameLineA(wchar_t *destination, size_t capacity) const;
    errno_t CopyNameLineB(wchar_t *destination, size_t capacity) const;
    unsigned char GetPercentStatA() const;
    unsigned char GetPercentStatB() const;
    unsigned char GetPercentStatC() const;
    signed char GetNationId() const;
    signed char GetSpiritId() const;
    unsigned int GetDisplayValueA() const;
    unsigned int GetDisplayValueB() const;
    unsigned int GetDisplayValueC() const;
    void SetDisplayLineA(const wchar_t *text);
    void SetDisplayLineB(const wchar_t *text);
    void SetStatusIconId(unsigned char iconId);

protected:
    virtual bool HandleStatusPacketEvent(const PaneEvent *event);
    virtual void OnPaint();

private:
    void InvalidateSummaryText();
    void GetStatusFieldRect(int fieldId, RectBounds *bounds);
    void DrawStatusGlyphText(const wchar_t *text, int x, int y, int glyphRow);
    void ApplyStatusPayload(const unsigned char *packet);

    void *m_numberGlyphs;
    wchar_t m_nameLine[64];
    wchar_t m_displayLineA[64];
    wchar_t m_secondaryLine[64];
    signed char m_nationId;
    unsigned char m_nationReserved;
    signed char m_spiritId;
    unsigned char m_statusIconId;
    unsigned char m_statusClassByte;
    unsigned char m_percentStatA;
    unsigned char m_percentStatB;
    unsigned char m_percentStatC;
    unsigned char m_inventorySlotCount;
    unsigned int m_displayPairValueA;
    unsigned int m_displayValueA;
    unsigned int m_displayPairValueB;
    unsigned int m_displayValueB;
    unsigned int m_displayValueC;
    unsigned int m_displayPairValueC;
    unsigned int m_reservedSummaryValueA;
    unsigned int m_reservedSummaryValueB;
};

extern UserStatusPane *g_activeUserStatusPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation note: field and helper names are inferred source-facing names. Support prose must say that the class shell is a reconstruction scaffold, not proof of exact original member names.

### [UID:0001NM] `by-memory/0x005b83b0-0x005baafe.UserStatusPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Method bodies for the UserStatusPane aggregate are split to exact child pages
// [UID:0003A8]-[UID:0003AF], [UID:0001NN], and [UID:0002LP]; this aggregate has no standalone C++ body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0001NN] `by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
errno_t UserStatusPane::CopyNameLineA(wchar_t *destination, size_t capacity) const
{
    return wcscpy_s(destination, capacity, m_nameLine);
}

errno_t UserStatusPane::CopyNameLineB(wchar_t *destination, size_t capacity) const
{
    return wcscpy_s(destination, capacity, m_secondaryLine);
}

unsigned char UserStatusPane::GetPercentStatA() const { return m_percentStatA; }
unsigned char UserStatusPane::GetPercentStatB() const { return m_percentStatB; }
unsigned char UserStatusPane::GetPercentStatC() const { return m_percentStatC; }
signed char UserStatusPane::GetNationId() const { return m_nationId; }
signed char UserStatusPane::GetSpiritId() const { return m_spiritId; }
unsigned int UserStatusPane::GetDisplayValueA() const { return m_displayValueA; }
unsigned int UserStatusPane::GetDisplayValueB() const { return m_displayValueB; }
unsigned int UserStatusPane::GetDisplayValueC() const { return m_displayValueC; }

void UserStatusPane::SetDisplayLineA(const wchar_t *text)
{
    wcscpy_s(m_displayLineA, 64, text);
    InvalidateSummaryText();
}

void UserStatusPane::SetDisplayLineB(const wchar_t *text)
{
    wcscpy_s(m_secondaryLine, 64, text);
    InvalidateSummaryText();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002LP] `by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserStatusPane::SetStatusIconId(unsigned char iconId)
{
    m_statusIconId = iconId;
    InvalidateSummaryText();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002YZ] `by-memory/0x00630c2c-0x00630cb4.UserStatusPaneVtableData.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this UserStatusPane vtable-data range is covered by [UID:0000FS] UserStatusPane class declarations.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000FT] `by-class/UserStatusPane2.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct RectBounds;
struct PaneEvent;

class UserStatusPane2 : public Pane
{
public:
    UserStatusPane2();
    virtual ~UserStatusPane2();

protected:
    virtual bool HandleStatusPacketEvent(const PaneEvent *event);
    virtual bool AlwaysFalse();
    virtual void OnPaint();

private:
    void InvalidateStatusFieldRect(int fieldId);
    void GetStatusFieldRect(int fieldId, RectBounds *bounds);
    void DrawGlyphText(const wchar_t *text, int x, int y, int glyphRow);
    void ApplyStatusPayload(const unsigned char *packet);

    void *m_numberGlyphs;
    int m_positionX;
    int m_positionY;
    unsigned int m_valueA;
    unsigned int m_valueB;
    unsigned int m_valueC;
    unsigned int m_valueD;
    unsigned int m_valueE;
    unsigned char m_statusByte;
    unsigned int m_valueF;
};

extern UserStatusPane2 *g_pUserStatusPane2;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation note: field names are descriptive placeholders. The destination support prose should preserve the current raw-helper/body uncertainty for [UID:0001NO].

### [UID:0001NO] `by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UserStatusPane2 method-body emission is not owned by this broad aggregate; this page records constructor/router/paint/payload ownership and has no standalone C++ body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002Z0] `by-memory/0x00630cb4-0x00630d3c.UserStatusPane2VtableData.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this UserStatusPane2 vtable-data range is covered by [UID:0000FT] UserStatusPane2 class declarations.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002Z3] `by-memory/0x00630e58-0x00630edc.OldUserStatusPaneVtableData.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this OldUserStatusPane vtable-data range is covered by [UID:00009U] OldUserStatusPane class declarations.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000PS] `by-global/g_activeUserStatusPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
UserStatusPane *g_activeUserStatusPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0001PE] `by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted storage for g_activeUserStatusPane is covered by [UID:0000PS] g_activeUserStatusPane.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000SN] `by-global/g_pUserStatusPane2.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
UserStatusPane2 *g_pUserStatusPane2 = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002WE] `by-memory/0x0069b4e4-0x0069b4e8.g_pUserStatusPane2.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted storage for g_pUserStatusPane2 is covered by [UID:0000SN] g_pUserStatusPane2.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000RV] `by-global/g_pOldUserStatusPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
OldUserStatusPane *g_pOldUserStatusPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002WG] `by-memory/0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted storage for g_pOldUserStatusPane is covered by [UID:0000RV] g_pOldUserStatusPane.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Support Doc Plan

Implementation callback should re-read each file immediately before editing and acquire only short leases for files about to be edited.

Required primary target edit:

- `by-file/UserStatusPane.md`: add a B009 empty-emitter-family source-quality section with this report's inventory, MCP provenance summary, current-zero singleton evidence, resource-string no-standalone policy, rejected alternatives, and score rationale. Update score to `90/87` only after support edits are applied or already present.

Required support edits:

- `by-class/UserStatusPane.md`: add [UID:0000FS] formal class shell, update stale gate language, preserve inferred-name caveats, and mention that exact child/body pages own bodies.
- `by-memory/0x005b83b0-0x005baafe.UserStatusPane.md`: add [UID:0001NM] marker-only aggregate block and update stale parent/file gate language.
- `by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md`: add [UID:0001NN] formal accessor/setter C++, preserve inferred field/helper names, and cite MCP decompile evidence.
- `by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md`: add [UID:0002LP] formal setter C++ and cite MCP decompile evidence.
- `by-memory/0x00630c2c-0x00630cb4.UserStatusPaneVtableData.md`: add [UID:0002YZ] vtable covered-by marker and preserve vtable-address evidence.
- `by-type/by-struct/UserStatusPaneSummaryFields.md`: convert [UID:0001WF] to non-reconstructable support layout documentation, with blank `EMITTER_UIDS` and blank formal C++; preserve field layout evidence and B004 caveats.
- `by-class/UserStatusPane2.md`: add [UID:0000FT] formal class shell, preserve broad-body uncertainty for [UID:0001NO], and keep split/body work out of this callback unless separately authorized.
- `by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md`: add [UID:0001NO] marker-only aggregate block and preserve exact `0x005bc60c` padding / `0x005bc610` successor boundary.
- `by-memory/0x00630cb4-0x00630d3c.UserStatusPane2VtableData.md`: add [UID:0002Z0] vtable covered-by marker and preserve MenuVariety negative boundary.
- `by-global/g_activeUserStatusPane.md`: add [UID:0000PS] zero-initialized global definition and current-zero MCP evidence.
- `by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md`: change [UID:0001PE] owner/emitter to [UID:0000PS] and add covered-by storage marker.
- `by-global/g_pUserStatusPane2.md`: add [UID:0000SN] zero-initialized global definition and historicalize stale `ff ff ff ff` initializer text.
- `by-memory/0x0069b4e4-0x0069b4e8.g_pUserStatusPane2.md`: add [UID:0002WE] storage covered-by marker and replace stale initializer language with current-zero evidence.
- `by-global/g_pOldUserStatusPane.md`: add [UID:0000RV] zero-initialized global definition and historicalize stale `ff ff ff ff` initializer text.
- `by-memory/0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md`: add [UID:0002WG] storage covered-by marker and preserve current-zero supersession evidence.
- `by-memory/0x00630e58-0x00630edc.OldUserStatusPaneVtableData.md`: add [UID:0002Z3] vtable covered-by marker.
- `by-memory/0x00630edc-0x00630f8c.UserStatusPaneResourceStrings.md`: add or strengthen no-standalone string-literal proof and keep formal C++ blank.

Already-present / conditional support:

- `by-memory/0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString.md`: no edit required if B014 no-standalone shared literal language is still present. If current content lacks that accepted proof, add only prose, not a comment emitter or data C++ block.
- [UID:0001NR] OldUserStatusPane aggregate and OldUserStatusPane exact child pages: no edit for this report. Current generated output already reflects B002 accepted implementation.
- Additional exact body pages for [UID:0001NM] and [UID:0001NO]: intentionally deferred. This report is an empty-emitter family source-quality pass, not a new split-page creation callback.

## Rejected Alternatives

- Do not paste decompiler-derived monolithic bodies into [UID:0001NM] or [UID:0001NO]. MCP shows those ranges are broad aggregates with child/split ownership concerns.
- Do not create a standalone `CharacterSummaryRecord` source type for [UID:0001WF]. B004 already rejected the generated pseudo-class as source-real output.
- Do not add comment-only emitters to [UID:00044W] or fabricate string data definitions for [UID:0003JC]. B014 established that shared source literals should remain source-use evidence and emit inside consuming bodies.
- Do not preserve `ff ff ff ff` initializer language as current fact for [UID:0000SN], [UID:0000RV], [UID:0002WE], or [UID:0002WG]. Current MCP storage bytes are zero.
- Do not re-route OldUserStatusPane bodies or edit [UID:0001NR] as part of this report. B002 already handled that family.
- Do not edit generated files, coverage reports, validator state, IDA DB, supervisor ledgers, executed archives, or lock files.

## Callback Implementation Results

Changed by-* files:

- `by-file/UserStatusPane.md`
- `by-class/UserStatusPane.md`
- `by-memory/0x005b83b0-0x005baafe.UserStatusPane.md`
- `by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md`
- `by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md`
- `by-memory/0x00630c2c-0x00630cb4.UserStatusPaneVtableData.md`
- `by-type/by-struct/UserStatusPaneSummaryFields.md`
- `by-class/UserStatusPane2.md`
- `by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md`
- `by-memory/0x00630cb4-0x00630d3c.UserStatusPane2VtableData.md`
- `by-global/g_activeUserStatusPane.md`
- `by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md`
- `by-global/g_pUserStatusPane2.md`
- `by-memory/0x0069b4e4-0x0069b4e8.g_pUserStatusPane2.md`
- `by-global/g_pOldUserStatusPane.md`
- `by-memory/0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md`
- `by-memory/0x00630e58-0x00630edc.OldUserStatusPaneVtableData.md`
- `by-memory/0x00630edc-0x00630f8c.UserStatusPaneResourceStrings.md`

Already-present/no-edit support:

- `by-memory/0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString.md`: B014-style no-standalone proof, `CANONICAL_OWNER:NONE`, source-use emitters `0000JL,0000HO,0000P2`, and blank formal C++ were already present. No edit was made.

Leases:

- Acquired short B009 leases for the 18 changed by-* files immediately before applying edits; every requested lease returned `Success`.
- Release command after validation returned `Rejected[No active lease]` for each path because the short leases had already expired during the validator batch.
- Acquired a second short B009 lease batch for 9 stale-text cleanup files; every requested lease returned `Success`.
- Released the second lease batch successfully after revalidation. A sequential shared `tools/leaser/Agents/current_leases.md` check showed no B009 rows; other agents' unrelated leases were present.

No forbidden manual edits:

- No manual edits were made to generated files, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files.
- Validator-owned generated/autogen side effects occurred through scoped validator commands: `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp`, generated reports, projected stats, research tracker, memory auto coverage, and validator autogen backups refreshed as part of validator execution.

## Validators For Implementation Callback

Command form used for each changed by-* file from `E:/NTK/GhidraBridge/source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0000P2-UserStatusPane-empty-emitter-family-source-quality-removed.md](0000P2-UserStatusPane-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

| File | command_id | command_timestamp | Exit | ok | generated_refresh | Notes |
| --- | --- | --- | ---: | ---: | --- | --- |
| `by-file/UserStatusPane.md` | `000000002167` | `2026-06-30T04:31:47-04:00` | 0 | 1 | completed, same id/timestamp | Warnings: missing_ref_uid `0003A8`, `0003AF`; validator also inserted UID links and refreshed generated output. |
| `by-class/UserStatusPane.md` | `000000002202` | `2026-06-30T04:43:46-04:00` | 0 | 1 | completed, same id/timestamp | Revalidation after historical-note cleanup. Warnings: missing_ref_uid for preexisting exact child UIDs `0003A8`-`0003AF`/`0003AB`. |
| `by-memory/0x005b83b0-0x005baafe.UserStatusPane.md` | `000000002170` | `2026-06-30T04:33:00-04:00` | 0 | 1 | completed, same id/timestamp | Warnings: missing_ref_uid for preexisting exact child UID references. |
| `by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md` | `000000002171` | `2026-06-30T04:33:22-04:00` | 0 | 1 | completed, same id/timestamp | No warnings. |
| `by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md` | `000000002204` | `2026-06-30T04:43:58-04:00` | 0 | 1 | completed, same id/timestamp | Revalidation after historical-note cleanup. No warnings. |
| `by-memory/0x00630c2c-0x00630cb4.UserStatusPaneVtableData.md` | `000000002173` | `2026-06-30T04:34:04-04:00` | 0 | 1 | completed, same id/timestamp | No warnings. |
| `by-type/by-struct/UserStatusPaneSummaryFields.md` | `000000002217` | `2026-06-30T04:45:35-04:00` | 0 | 1 | completed, same id/timestamp | Revalidation after historical-note cleanup. No warnings. |
| `by-class/UserStatusPane2.md` | `000000002215` | `2026-06-30T04:45:18-04:00` | 0 | 1 | completed, same id/timestamp | Revalidation after historical-note cleanup. No warnings. |
| `by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md` | `000000002214` | `2026-06-30T04:44:58-04:00` | 0 | 1 | completed, same id/timestamp | Revalidation after historical-note cleanup. No warnings. |
| `by-memory/0x00630cb4-0x00630d3c.UserStatusPane2VtableData.md` | `000000002177` | `2026-06-30T04:34:55-04:00` | 0 | 1 | completed, same id/timestamp | No warnings. |
| `by-global/g_activeUserStatusPane.md` | `000000002206` | `2026-06-30T04:44:09-04:00` | 0 | 1 | completed, same id/timestamp | Revalidation after historical-note cleanup. No warnings. |
| `by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md` | `000000002208` | `2026-06-30T04:44:22-04:00` | 0 | 1 | completed, same id/timestamp | Revalidation after historical-note cleanup. Warnings: missing_ref_uid `0003U9`, preexisting B006 support reference. |
| `by-global/g_pUserStatusPane2.md` | `000000002210` | `2026-06-30T04:44:34-04:00` | 0 | 1 | completed, same id/timestamp | Revalidation after historical-note cleanup. No warnings. |
| `by-memory/0x0069b4e4-0x0069b4e8.g_pUserStatusPane2.md` | `000000002181` | `2026-06-30T04:35:41-04:00` | 0 | 1 | completed, same id/timestamp | No warnings. |
| `by-global/g_pOldUserStatusPane.md` | `000000002212` | `2026-06-30T04:44:46-04:00` | 0 | 1 | completed, same id/timestamp | Revalidation after historical-note cleanup. No warnings. |
| `by-memory/0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md` | `000000002184` | `2026-06-30T04:36:05-04:00` | 0 | 1 | completed, same id/timestamp | No warnings. |
| `by-memory/0x00630e58-0x00630edc.OldUserStatusPaneVtableData.md` | `000000002185` | `2026-06-30T04:36:18-04:00` | 0 | 1 | completed, same id/timestamp | No warnings. |
| `by-memory/0x00630edc-0x00630f8c.UserStatusPaneResourceStrings.md` | `000000002186` | `2026-06-30T04:36:30-04:00` | 0 | 1 | completed, same id/timestamp | No warnings. |

Generated freshness:

- `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` header after validation:
  - `validator-command-id: 000000002233`
  - `validator-refreshed-at: 2026-06-30T04:48:12-04:00`
  - `validator-refresh-source: foreground-generated-refresh`
- The generated header is newer than the final B009 file revalidation command `000000002217`, so generated output is fresh for all callback edits.
- Generated output contains the accepted class shells, [UID:0001NM]/[UID:0001NO] aggregate markers, [UID:0001NN] accessor C++, [UID:0002LP] setter C++, vtable markers, and global definitions.
- Remaining empty generated markers are [UID:00044W] and [UID:0003JC] only; both are intentional no-standalone source-literal dispositions under B014/B009.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Callback verification state/proof |
| --- | --- | --- | --- | --- | --- | --- |
| C0000P2-01 | [UID:0000P2] is a source-real UserStatusPane file family rooted at `NexusTK/ui/panels/UserStatusPane.cpp`. | High | Generated root exists; by-file metadata; tracker row 27 total markers. | `by-file/UserStatusPane.md` metadata and B009 section | incorporate | applied: target metadata now `90/87`, `CANONICAL_OWNER:FILE`, path unchanged; validator `000000002167`. |
| C0000P2-02 | Current generated output has 18 empty markers in the UserStatusPane family. | High | Current generated marker inventory; tracker row total 27/filled 9/empty 18. | `by-file/UserStatusPane.md` B009 section | incorporate | applied: B009 section records the 18-marker disposition table; generated output after `000000002186` leaves only intentional literal markers. |
| C0000P2-03 | [UID:0000FS] should emit a class declaration shell with `[[CHILDREN]]`, not remain blank. | Medium-high | by-class method map; B003/B002 class-shell precedent; current empty generated marker. | `by-class/UserStatusPane.md` C++ block and notes | incorporate | applied: formal class shell inserted; generated output lines under UID `0000FS`; revalidated by `000000002202`. |
| C0000P2-04 | [UID:0001NM] is a broad aggregate and should not receive monolithic function bodies. | High | MCP `lookup_funcs` shows child functions and padding at `0x005baafe`; doc child coverage list. | `by-memory/0x005b83b0-0x005baafe.UserStatusPane.md` C++ block and Item Summary | incorporate | applied: marker-only block and updated item summary/decision; generated output includes UID `0001NM` marker; validator `000000002170`. |
| C0000P2-05 | [UID:0001NN] exact accessor island is reconstructable first-draft C++. | High | MCP decompile at `0x005b85b0`, `0x005b8670`, `0x005b86a0`; B004 accepted accessor island. | `by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md` C++ block and evidence | incorporate | applied: formal accessor/setter C++ inserted and generated under UID `0001NN`; validator `000000002171`. |
| C0000P2-06 | [UID:0002LP] writes `this[639]` / status icon id and invalidates the summary field. | High | MCP decompile at `0x005b86e0`. | `by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md` C++ block and evidence | incorporate | applied: formal `SetStatusIconId` C++ inserted and generated under UID `0002LP`; revalidated by `000000002204`. |
| C0000P2-07 | [UID:0002YZ] UserStatusPane vtable data is source-declared/generated-binary support covered by [UID:0000FS]. | High | MCP entity names at `0x00630c2c`, xrefs to constructor/destructor sites. | `by-memory/0x00630c2c-0x00630cb4.UserStatusPaneVtableData.md` C++ block and notes | incorporate | applied: covered-by marker inserted and generated under UID `0002YZ`; validator `000000002173`. |
| C0000P2-08 | [UID:0001WF] is not a standalone source type and should become non-reconstructable layout support. | High | B004 CharacterSummaryRecord report; by-struct doc content; no standalone source type evidence. | `by-type/by-struct/UserStatusPaneSummaryFields.md` metadata and notes | incorporate | applied: `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, layout-support decision added; revalidated by `000000002217`. |
| C0000P2-09 | [UID:0000FT] should emit a UserStatusPane2 class shell with `[[CHILDREN]]`. | Medium-high | by-class method map; MCP constructor/vtable evidence; B003 class-shell precedent. | `by-class/UserStatusPane2.md` C++ block and notes | incorporate | applied: formal class shell inserted and generated under UID `0000FT`; revalidated by `000000002215`. |
| C0000P2-10 | [UID:0001NO] is a broad UserStatusPane2 aggregate and should not receive monolithic bodies in this callback. | High | MCP `lookup_funcs`, padding at `0x005bc60c`, successor `0x005bc610`; current doc raw-helper caveats. | `by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md` C++ block and evidence | incorporate | applied: marker-only block and supervisor exclusion reason added; generated under UID `0001NO`; revalidated by `000000002214`. |
| C0000P2-11 | [UID:0002Z0] UserStatusPane2 vtable data is covered by [UID:0000FT]. | High | MCP entity names at `0x00630cb4`; MenuVariety vtables begin at `0x00630d3c`. | `by-memory/0x00630cb4-0x00630d3c.UserStatusPane2VtableData.md` C++ block and notes | incorporate | applied: covered-by marker inserted and generated under UID `0002Z0`; validator `000000002177`. |
| C0000P2-12 | `g_activeUserStatusPane` storage is currently zero-initialized and should emit `UserStatusPane *g_activeUserStatusPane = NULL;`. | High | MCP bytes `00 00 00 00` at `0x0069ae0c`; xref count 67. | `by-global/g_activeUserStatusPane.md` C++ block and evidence | incorporate | applied: formal global definition inserted and generated under UID `0000PS`; revalidated by `000000002206`. |
| C0000P2-13 | [UID:0001PE] should be routed to [UID:0000PS] and emit only a covered-by storage marker. | High | Storage child is exact range for same global; B003 exact-storage precedent. | `by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md` metadata and C++ block | incorporate | applied: owner/emitter changed to `0000PS`, marker inserted; revalidated by `000000002208`. |
| C0000P2-14 | `g_pUserStatusPane2` storage is currently zero-initialized and stale `ff` language should be historicalized. | High | MCP bytes `00 00 00 00` at `0x0069b4e4`; xref count 6. | `by-global/g_pUserStatusPane2.md`; `by-memory/0x0069b4e4-0x0069b4e8.g_pUserStatusPane2.md` | historicalize | applied: global emits `NULL`, stale `ff` language historicalized in global and storage child; validators `000000002210`, `000000002181`. |
| C0000P2-15 | [UID:0002WE] should emit only a covered-by storage marker for [UID:0000SN]. | High | Exact storage child route; B003 exact-storage precedent. | `by-memory/0x0069b4e4-0x0069b4e8.g_pUserStatusPane2.md` C++ block and notes | incorporate | applied: covered-by marker inserted; validator `000000002181`. |
| C0000P2-16 | `g_pOldUserStatusPane` storage is currently zero-initialized and stale `ff` language should be historicalized. | High | MCP bytes `00 00 00 00` at `0x0069b4ec`; xref count 9. | `by-global/g_pOldUserStatusPane.md`; `by-memory/0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md` | historicalize | applied: global emits `NULL`, stale `ff` language historicalized in global and storage child; validators `000000002212`, `000000002184`. |
| C0000P2-17 | [UID:0002WG] should emit only a covered-by storage marker for [UID:0000RV]. | High | Exact storage child route; B003 exact-storage precedent. | `by-memory/0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md` C++ block and notes | incorporate | applied: covered-by marker inserted; validator `000000002184`. |
| C0000P2-18 | [UID:0002Z3] OldUserStatusPane vtable data is covered by [UID:00009U]. | High | MCP entity names at `0x00630e58`; accepted B002 OldUserStatusPane pattern. | `by-memory/0x00630e58-0x00630edc.OldUserStatusPaneVtableData.md` C++ block and notes | incorporate | applied: covered-by marker inserted and generated under UID `0002Z3`; validator `000000002185`. |
| C0000P2-19 | [UID:00044W] `NPAL5.PAL` is shared source-use literal evidence and should not get a comment emitter. | High | B014 accepted report; MCP xrefs to FrameChrome, BackPane, UserStatusPane, OldUserStatusPane. | `by-memory/0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString.md`; `by-file/UserStatusPane.md` note | already-present | already-present: page already had `CANONICAL_OWNER:NONE`, emitters `0000JL,0000HO,0000P2`, no-code disposition, and blank formal C++; by-file B009 section records it. |
| C0000P2-20 | [UID:0003JC] UserStatusPane resource strings are source-use literals and should keep formal C++ blank. | High | MCP decoded literal bytes and xref at `0x005b8cd0`; B014 string-literal precedent. | `by-memory/0x00630edc-0x00630f8c.UserStatusPaneResourceStrings.md`; `by-file/UserStatusPane.md` note | incorporate | applied: no-standalone proof added, formal C++ left blank by design; validator `000000002186`; generated empty marker remains intentional. |
| C0000P2-21 | MenuVariety vtables and successor resource/function boundaries are negative evidence against extending UserStatusPane ranges. | High | MCP entity name at `0x00630d3c`; xref to `0x00630f8c`; successor function `0x005bc610`. | Relevant vtable/resource/aggregate support docs | incorporate | applied: preserved in by-file B009 section, `0001NO`, `0002Z0`, and `0003JC`; validators `000000002167`, `000000002214`, `000000002177`, `000000002186`. |
| C0000P2-22 | OldUserStatusPane aggregate/body implementation should not be edited by this report. | High | B002 accepted implementation; current generated output already has [UID:0001NR] and exact child bodies. | Report and `by-file/UserStatusPane.md` B009 section | not-applicable | excluded-with-reason: no edit to [UID:0001NR] or exact body child pages; by-file and `0002Z3` notes preserve accepted B002 route. |
| C0000P2-23 | Implementation should not edit generated files, coverage reports, validator state, IDA DB, supervisor ledgers, executed archives, or lock files. | High | User instructions and workflow constraints. | Implementation checkpoint/report ledger | incorporate | applied: only by-* docs and this B009 report were manually edited; generated/report/state changes were validator-owned. |
| C0000P2-24 | Validators must be scoped to changed by-* files and use generated freshness checks for the file/class/root output. | High | Workflow and user assignment. | Implementation checkpoint/report ledger | incorporate | applied: 18 initial scoped validators plus 9 stale-text revalidators ran with `--wait-generated`, exit 0, ok 1; latest observed generated header is `000000002233`. |
| C0000P2-25 | Additional exact body split pages for UserStatusPane2 are outside this report-first implementation scope. | Medium-high | No exact child pages currently exist for most [UID:0001NO] bodies; broad raw-helper uncertainty. | `by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md`; report checklist | not-applicable | excluded-with-reason: supervisor clarification explicitly excludes new split pages; `0001NO` and by-file document marker-only route. |

## Implementation Tracking Checklist

- [x] Acquire short leases only for files about to be edited; release each lease immediately after the edit/validator batch. Proof: 18 initial lease requests returned `Success`; the first post-validation release attempt found no active leases because they expired. A second 9-file cleanup lease batch returned `Success` and was released successfully; final shared lease report showed no B009 rows.
- [x] Re-read `by-file/UserStatusPane.md` immediately before editing. Proof: current content was read before patching.
- [x] Update `by-file/UserStatusPane.md` metadata to `COMPLETION:90`, `CONFIDENCE:87`, preserve `CANONICAL_OWNER:FILE`. Proof: applied and validated by `000000002167`. `RECONSTRUCTABLE`/`EMITTER_UIDS` by-file header lines are not applicable under current by-structure metadata rules, so no excluded metadata lines were added.
- [x] Add a B009 empty-emitter-family source-quality section to `by-file/UserStatusPane.md` with MCP provenance, generated marker inventory, current-zero singleton evidence, resource-string no-standalone policy, and rejected alternatives. Proof: applied and validated by `000000002167`.
- [x] Re-read `by-class/UserStatusPane.md`; add [UID:0000FS] formal class-shell C++ with `[[CHILDREN]]`, and preserve inferred-name caveats. Proof: applied and revalidated by `000000002202`.
- [x] Re-read `by-memory/0x005b83b0-0x005baafe.UserStatusPane.md`; add [UID:0001NM] marker-only aggregate block and fix stale below-gate/file-parent language. Proof: applied and validated by `000000002170`.
- [x] Re-read `by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md`; add [UID:0001NN] formal accessor/setter C++ and cite MCP decompile evidence. Proof: applied and validated by `000000002171`.
- [x] Re-read `by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md`; add [UID:0002LP] formal setter C++ and cite MCP decompile evidence. Proof: applied and revalidated by `000000002204`.
- [x] Re-read `by-memory/0x00630c2c-0x00630cb4.UserStatusPaneVtableData.md`; add [UID:0002YZ] covered-by marker for [UID:0000FS]. Proof: applied and validated by `000000002173`.
- [x] Re-read `by-type/by-struct/UserStatusPaneSummaryFields.md`; change [UID:0001WF] to non-reconstructable layout support, blank `EMITTER_UIDS`, blank optional position, blank formal C++, and preserve B004 caveats. Proof: applied and revalidated by `000000002217`.
- [x] Re-read `by-class/UserStatusPane2.md`; add [UID:0000FT] formal class-shell C++ with `[[CHILDREN]]`, and preserve [UID:0001NO] raw-helper/body uncertainty. Proof: applied and revalidated by `000000002215`.
- [x] Re-read `by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md`; add [UID:0001NO] marker-only aggregate block and preserve `0x005bc60c` padding / `0x005bc610` successor boundary. Proof: applied and revalidated by `000000002214`.
- [x] Re-read `by-memory/0x00630cb4-0x00630d3c.UserStatusPane2VtableData.md`; add [UID:0002Z0] covered-by marker for [UID:0000FT] and preserve MenuVariety boundary evidence. Proof: applied and validated by `000000002177`.
- [x] Re-read `by-global/g_activeUserStatusPane.md`; add [UID:0000PS] zero-initialized global C++ and current-zero storage evidence. Proof: applied and revalidated by `000000002206`.
- [x] Re-read `by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md`; re-route [UID:0001PE] to [UID:0000PS] owner/emitter and add storage covered-by marker. Proof: applied and revalidated by `000000002208`.
- [x] Re-read `by-global/g_pUserStatusPane2.md`; add [UID:0000SN] zero-initialized global C++ and historicalize stale `ff ff ff ff` initializer language. Proof: applied and revalidated by `000000002210`.
- [x] Re-read `by-memory/0x0069b4e4-0x0069b4e8.g_pUserStatusPane2.md`; add [UID:0002WE] storage covered-by marker and replace stale initializer language with current-zero evidence. Proof: applied and validated by `000000002181`.
- [x] Re-read `by-global/g_pOldUserStatusPane.md`; add [UID:0000RV] zero-initialized global C++ and historicalize stale `ff ff ff ff` initializer language. Proof: applied and revalidated by `000000002212`.
- [x] Re-read `by-memory/0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md`; add [UID:0002WG] storage covered-by marker and preserve current-zero supersession evidence. Proof: applied and validated by `000000002184`.
- [x] Re-read `by-memory/0x00630e58-0x00630edc.OldUserStatusPaneVtableData.md`; add [UID:0002Z3] covered-by marker for [UID:00009U] and do not edit [UID:0001NR] body docs. Proof: applied and validated by `000000002185`; no [UID:0001NR] edit made.
- [x] Re-read `by-memory/0x00630edc-0x00630f8c.UserStatusPaneResourceStrings.md`; add/strengthen source-use no-standalone proof while leaving formal C++ blank. Proof: applied and validated by `000000002186`.
- [x] Re-read `by-memory/0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString.md`; if B014 proof is still present, mark already-present and make no edit; if missing, add only prose, not marker/data C++. Proof: already present at same-or-greater detail; no edit made.
- [x] Do not create new exact split/body pages for [UID:0001NO] under this callback; mark as excluded-with-reason unless supervisor separately authorizes split creation. Proof: no new pages created; `0001NO` records supervisor exclusion.
- [x] Do not edit [UID:0001NR] or OldUserStatusPane exact body child pages; mark as already-present per accepted B002 implementation. Proof: no [UID:0001NR] or exact body child pages changed.
- [x] Do not edit generated files, `*-coverage-report.md`, project-level generated reports, validator/tool state, IDA DB, supervisor ledgers, executed archives, or lock files. Proof: only by-* docs and this report were manually edited; validator-owned generated side effects are listed above.
- [x] Run scoped validators for every changed by-* file from `E:/NTK/GhidraBridge/source-3/project-documentation`. Proof: 18 initial file validators plus 9 cleanup revalidators, all exit 0 and `ok: 1`.
- [x] Use `--wait-generated` for target/class/file validators where generated `NexusTK/ui/panels/UserStatusPane.cpp` freshness matters. Proof: every validator command used `--wait-generated`.
- [x] Confirm generated `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` command ID/timestamp after validation. Proof: latest observed header `validator-command-id: 000000002233`, `validator-refreshed-at: 2026-06-30T04:48:12-04:00`, newer than final B009 file revalidation command `000000002217`.
- [x] Record validator command IDs, timestamps, exit codes, ok counts, generated freshness, changed files, leases used/released, and any intentional no-standalone literal markers in the callback checkpoint. Proof: recorded in this report and final checkpoint.
- [x] Update this report's ledger/checklist during implementation callback with `applied`, `already-present`, `excluded-with-reason`, or `blocked` states and proof. Proof: ledger and checklist updated above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0000P2-UserStatusPane-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0000P2-UserStatusPane-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T04:50:35","uid":"0000P2"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000P2-UserStatusPane-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/0000P2-UserStatusPane-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000P2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
