const int GEB_RPC_HIGH = 1734697576;		// "gebh": the server sends a smoker their high (seconds left, strength)

// The high on screen, on the smoker's own client (geb_HighClient in scripts/4_world/entities/geb_joint.c drives it
// each frame with its strength). The colours roll round the rainbow: the whole picture tinted one hue after another
// (the colourisation layer vanilla's toxic zones shift), its edges in the opposite hue (the vignette's colour), bright
// things glowing a little more, rainbow fringes at the edges of the screen and a touch more contrast. Everything scales
// with the strength; at 0 the requester stops and vanilla's values come back.
class PPERequester_GebHigh extends PPERequester_GameplayBase
{
	// our own priority layers (vanilla's on these parameters are 100-800; Geb's Mushrooms' trip uses 160 and 260)
	protected static const int L_TINT = 270;
	protected static const int L_VIGNETTE = 270;
	protected static const int L_GLOW = 270;
	protected static const int L_FRINGE = 170;

	protected float m_Time;

	override protected void OnStart(Param par = null)
	{
		super.OnStart(par);
		m_Time = 0;
	}

	// strength 0..1 now; delta: seconds since the last frame
	void SetHigh(float strength, float delta)
	{
		float s = Math.Clamp(strength, 0, 1);
		m_Time += delta;
		float t = m_Time;

		// once round the rainbow every 12 s: each channel pushed up and down a third of a turn apart
		float hue = t * Math.PI2 / 12;
		float amp = 0.55 * s;
		float r = 1 + amp * Math.Sin(hue);
		float g = 1 + amp * Math.Sin(hue + 2.094);
		float b = 1 + amp * Math.Sin(hue + 4.189);
		// scaled so the picture keeps its brightness and only its colour moves
		float lum = 0.299 * r + 0.587 * g + 0.114 * b;
		r = r / lum;
		g = g / lum;
		b = b / lum;
		SetTargetValueColor(PostProcessEffectType.Glow, PPEGlow.PARAM_COLORIZATIONCOLOR, {r, g, b, 0.0}, L_TINT, PPOperators.MULTIPLICATIVE);
		float contrast = 1 + 0.08 * s;
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_CONTRAST, false, contrast, L_TINT, PPOperators.HIGHEST);

		// the edges of the view in the opposite colour, so the picture runs from one hue in the middle to another round it
		float vignette = 0.5 * s;
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_VIGNETTE, false, vignette, L_VIGNETTE, PPOperators.ADD);
		float vr = 0.3 * s * (0.5 - 0.5 * Math.Sin(hue));
		float vg = 0.3 * s * (0.5 - 0.5 * Math.Sin(hue + 2.094));
		float vb = 0.3 * s * (0.5 - 0.5 * Math.Sin(hue + 4.189));
		SetTargetValueColor(PostProcessEffectType.Glow, PPEGlow.PARAM_VIGNETTECOLOR, {vr, vg, vb, 0.0}, L_VIGNETTE, PPOperators.ADD);

		// lights and bright sky bloom, breathing slowly
		float bloom = 1 + s * (0.6 + 0.3 * Math.Sin(t * 0.7));
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_BLOOMINTENSITY, false, bloom, L_GLOW, PPOperators.HIGHEST);

		// rainbow fringes at the edges of the screen, pulsing
		float fringe = 0.006 * s * (0.7 + 0.3 * Math.Sin(t * 1.1));
		SetTargetValueFloat(PostProcessEffectType.ChromAber, PPEChromAber.PARAM_POWERX, false, fringe, L_FRINGE, PPOperators.HIGHEST);
		SetTargetValueFloat(PostProcessEffectType.ChromAber, PPEChromAber.PARAM_POWERY, false, fringe, L_FRINGE, PPOperators.HIGHEST);
	}
};

// Registered the way vanilla asks mods to (PPERequesterRegistrations in pperequesterbank.c)
modded class PPERequesterRegistrations
{
	override protected void RegisterAdditionalRequesters()
	{
		super.RegisterAdditionalRequesters();
		PPERequesterBank.RegisterRequester(PPERequester_GebHigh);
	}
};
