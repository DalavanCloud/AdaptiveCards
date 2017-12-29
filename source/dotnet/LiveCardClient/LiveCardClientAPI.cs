﻿using AdaptiveCards;
using LiveCardAPI;
using StreamJsonRpc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Web;

namespace LiveCardClient
{
    /// <summary>
    /// api exposed to LiveCardServer so that it can manipulate the dom 
    /// </summary>
    public class LiveCardClientAPI : ILiveCardClientAPI
    {
        LiveCard liveCard;

        public LiveCardClientAPI(LiveCard card)
        {
            this.liveCard = card;
        }

        /// <summary>
        /// Insert new element
        /// </summary>
        /// <param name="id"></param>
        /// <param name="element"></param>
        /// <returns></returns>
        public async virtual Task OnInsertElement(InsertPosition position, string id, AdaptiveElement element)
        {
            var parent = await this.liveCard.Card.InsertElement(position, id, element);

            if (parent is AdaptiveElement)
                await this.liveCard.FireElementChanged((AdaptiveElement)parent);
            else
                await this.liveCard.FireCardChanged((AdaptiveCard)parent);
        }

        /// <summary>
        /// Replace element
        /// </summary>
        /// <param name="id"></param>
        /// <param name="element"></param>
        /// <returns></returns>
        public async virtual Task OnReplaceElement(AdaptiveElement element)
        {
            await this.liveCard.Card.ReplaceElement(element);

            await this.liveCard.FireElementChanged(element);
        }

        /// <summary>
        /// Remove element
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        public async virtual Task OnRemoveElement(string id)
        {
            var parent = await this.liveCard.Card.RemoveElement(id);

            if (parent is AdaptiveElement)
                await this.liveCard.FireElementChanged((AdaptiveElement)parent);
            else
                await this.liveCard.FireCardChanged((AdaptiveCard)parent);
        }

        /// <summary>
        /// SetProperties on element
        /// </summary>
        /// <param name="id"></param>
        /// <param name="properties"></param>
        /// <returns></returns>
        public async virtual Task OnSetProperties(string id, IEnumerable<SetProperty> properties)
        {
            await this.liveCard.Card.SetProperties(id, properties);

            if (this.liveCard.Card.TryGetElementById(id, out AdaptiveElement element))
                await this.liveCard.FireElementChanged(element);
        }

        /// <summary>
        /// Save the card
        /// </summary>
        /// <returns></returns>
        public virtual Task SaveCard(AdaptiveCard card = null)
        {
            return this.liveCard.SaveCard(card);
        }

        /// <summary>
        /// Close the card
        /// </summary>
        /// <returns></returns>
        public async virtual Task CloseCard()
        {
            await this.liveCard.CloseCard();
        }

    }
}